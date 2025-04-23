#include "CPlayer.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include  "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SphereComponent.h"

#include "CPlayerState.h"
#include "Item/CItemBase.h"
#include "Inventory/CInventoryComponent.h"
#include "Framework/CHUD.h"
#include "UI/CUI_MainHUD.h"
#include "Stats/CStatComponent.h"
#include "Player/CMovementComponent_Player.h"
#include "Interfaces/HPBarInteraction.h"



ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Player");

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	{
		Movement = CreateDefaultSubobject<UCMovementComponent_Player>("MovementComponent_Player");
		Weapon = CreateDefaultSubobject<UCWeaponComponent>("WeaponComponent");
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->bEnableCameraLag = true;
	SpringArm->TargetArmLength = 450;
	SpringArm->TargetOffset = FVector(0, 0, 450);
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	FollowCamera->SetupAttachment(SpringArm);
	FollowCamera->SetRelativeRotation(FRotator(-40.f, 0, 0));

	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetupAttachment(GetCapsuleComponent());
	SphereComponent->SetSphereRadius(500.f);

}

void ACPlayer::SetCurrentHealth(float InHealth)
{
	TargetHealth = FMath::Clamp(CurrentHealth + InHealth, 0.f, MaxHealth);
	bInterpolatingHealth = true;

	if (OnHealthBarUpdate.IsBound())
		OnHealthBarUpdate.Broadcast(GetCurrentHealthPercent());

	if (TargetHealth <= 0.f)
	{
		bIsDead = true;
		//PlayDead Animation
	}

}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	OnTakeAnyDamage.AddDynamic(this, &ACPlayer::OnPlayerTakeDamage);

	CurrentHealth = MaxHealth;
	CPlayerState = Cast<ACPlayerState>(GetController()->GetPlayerState<ACPlayerState>());

	InitializePlayerEnhnacedInput();

	if (!Movement) return;
	Movement->DisableControlRotation();

	HUD = GetWorld()->GetFirstPlayerController()->GetHUD<ACHUD>();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereComponentBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnSphereComponentEndOverlap);
}

void ACPlayer::InitializePlayerEnhnacedInput()
{
	APlayerController* playerController = Cast<APlayerController>(GetController());

	if (playerController)
	{
		if (playerController->GetLocalPlayer())
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());

			if (Subsystem && InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

void ACPlayer::PickupItem()
{
	FHitResult hitResult;
	UKismetSystemLibrary::SphereTraceSingle(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 10, 150, ETraceTypeQuery::TraceTypeQuery1, false, TArray<AActor*>{this}, EDrawDebugTrace::ForDuration, hitResult, true);

	if (!hitResult.GetActor()) return;
	if (!CPlayerState) return;

	if (hitResult.GetActor()->ActorHasTag("Item"))
	{
		if (ACItemBase* item = Cast<ACItemBase>(hitResult.GetActor()))
		{
			FItemStructure* itemData = &item->GetItemData();
			if (CPlayerState->GetInventoryComponent()->AddItemToInventory(itemData))
			{
				hitResult.GetActor()->Destroy();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("ACPlayer::Inventory is Full"));
			}
		}
	}
}

void ACPlayer::ToggleInventoryMenu()
{
	if (!HUD) return;

	HUD->ToggleInventory();
}

void ACPlayer::ToggleStatMenu()
{
	HUD->ToggleStat();
}


void ACPlayer::OnPlayerTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	float defense = CPlayerState->GetStatComponent()->GetStatValue(FName("Defense"));
	float FinalDamage = FMath::Clamp(Damage - defense, 0, 9999);

	if (FinalDamage > 0)
		SetCurrentHealth(-FinalDamage);

	PlayHitReactionMontage(DamageCauser, FinalDamage);

	if (OnHealthBarUpdate.IsBound())
		OnHealthBarUpdate.Broadcast(GetCurrentHealthPercent());

}

void ACPlayer::PlayHitReactionMontage(AActor* DamageCauser, float InDamageAmount)
{
	//if (GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return; //????

	if (!DamageCauser || !HitReactMontage) return;

	UE_LOG(LogTemp, Warning, TEXT("ACPlayer::OnPlayerTakeAnyDmage - Location %s"),*GetActorLocation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("ACPlayer::OnPlayerTakeAnyDmage - PlayerAddress %p"),this);
	


	FVector causerLocation = DamageCauser->GetActorLocation();
	FVector forwardDirection = GetActorForwardVector();
	FVector hitDirection = (causerLocation - GetActorLocation()).GetSafeNormal();

	float forwardDot = FVector::DotProduct(forwardDirection, hitDirection);
	float rightDot = FVector::CrossProduct(forwardDirection, hitDirection).Z;

	FName montageSectionName;

	if (FMath::Abs(forwardDot) > FMath::Abs(rightDot))
	{
		if (forwardDot > 0.f) //전방
		{
			if (InDamageAmount > 30.f)
			{
				montageSectionName = FName("HitFromFrontCritical");
			}
			else
			{
				int32 selection = FMath::RandRange(1, 4);
				switch (selection)
				{
				case 1: montageSectionName = FName("HitFromFront1"); break;
				case 2: montageSectionName = FName("HitFromFront2"); break;
				case 3: montageSectionName = FName("HitFromFront3"); break;
				case 4: montageSectionName = FName("HitFromFront4"); break;
				default: montageSectionName = FName("HitFromFront1");
				}
			}
		}
		else //후방
		{
			montageSectionName = (InDamageAmount > 30.f) ? FName("HitFromBackCritical") : FName("HitFromBack");
		}
	}
	else
	{
		if (rightDot > 0.f) //오른쪽
		{
			montageSectionName = FName("HitFromRight");
		}
		else //왼쪽
		{
			montageSectionName = FName("HitFromLeft");
		}
	}

	PlayAnimMontage(HitReactMontage, HitMontagePlayRate, montageSectionName);
}

void ACPlayer::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Enemy"))
	{
		if (IHPBarInteraction* hpBar = Cast<IHPBarInteraction>(OtherActor))
			hpBar->ShowHPBar();
	}
}

void ACPlayer::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Enemy"))
	{
		if (IHPBarInteraction* hpBar = Cast<IHPBarInteraction>(OtherActor))
			hpBar->HideHPBar();
	}
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInterpolatingHealth)
	{
		CurrentHealth = FMath::FInterpTo(CurrentHealth, TargetHealth, DeltaTime, 1.f);
		if (FMath::IsNearlyEqual(CurrentHealth, TargetHealth, 0.01f))
		{
			bInterpolatingHealth = false;
			CurrentHealth = TargetHealth;
			UE_LOG(LogTemp, Warning, TEXT("ACPlayer::CurrentHealth: %f"), CurrentHealth);
		}

		if (OnHealthBarUpdate.IsBound())
			OnHealthBarUpdate.Broadcast(GetCurrentHealthPercent());
	}
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!Movement) return;

	if (IA_MoveAction)
		enhancedInput->BindAction(IA_MoveAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent_Player::MoveAction);

	if (IA_DodgeAction)
		enhancedInput->BindAction(IA_DodgeAction, ETriggerEvent::Started, Movement, &UCMovementComponent_Player::Dodge);

	if (IA_KatanaAction)
		enhancedInput->BindAction(IA_KatanaAction, ETriggerEvent::Started, Weapon, &UCWeaponComponent::SetKatanaMode);

	if (IA_TestWeapon)
		enhancedInput->BindAction(IA_TestWeapon, ETriggerEvent::Started, Weapon, &UCWeaponComponent::TestWeaponMode);

	if (IA_BasicAttackAction)
		enhancedInput->BindActionValueLambda(IA_BasicAttackAction, ETriggerEvent::Started, [this](const FInputActionValue& value)
			{
				Weapon->DoSkill(ESkillKey::BasicCombo);
			});

	if (IA_SKill_Q)
		enhancedInput->BindActionValueLambda(IA_SKill_Q, ETriggerEvent::Started, [this](const FInputActionValue& value)
			{
				Weapon->DoSkill(ESkillKey::Q);
			});

	if (IA_SKill_W)
		enhancedInput->BindActionValueLambda(IA_SKill_W, ETriggerEvent::Started, [this](const FInputActionValue& value)
			{
				Weapon->DoSkill(ESkillKey::W);
			});

	if (IA_SKill_E)
		enhancedInput->BindActionValueLambda(IA_SKill_E, ETriggerEvent::Started, [this](const FInputActionValue& value)
			{
				Weapon->DoSkill(ESkillKey::E);
			});

	if (IA_SKill_R)
		enhancedInput->BindActionValueLambda(IA_SKill_R, ETriggerEvent::Started, [this](const FInputActionValue& value)
			{
				Weapon->DoSkill(ESkillKey::R);
			});

	if (IA_PickupAction)
		enhancedInput->BindAction(IA_PickupAction, ETriggerEvent::Started, this, &ACPlayer::PickupItem);

	if (IA_InventoryAction)
		enhancedInput->BindAction(IA_InventoryAction, ETriggerEvent::Started, this, &ACPlayer::ToggleInventoryMenu);

	if (IA_StatAction)
		enhancedInput->BindAction(IA_StatAction, ETriggerEvent::Started, this, &ACPlayer::ToggleStatMenu);
}
