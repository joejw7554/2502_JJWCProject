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

#include "CPlayerState.h"
#include "Item/CItemBase.h"
#include "Inventory/CInventoryComponent.h"
#include "Framework/CHUD.h"
#include "UI/CUI_MainHUD.h"


ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Player");

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	//Components
	{
		Movement = CreateDefaultSubobject<UCMovementComponent>("MovementComponent");
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

}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	CPlayerState = Cast<ACPlayerState>(GetPlayerState());

	InitializePlayerEnhnacedInput();

	if (!Movement) return;
	Movement->DisableControlRotation();

	HUD = GetWorld()->GetFirstPlayerController()->GetHUD<ACHUD>();
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



void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!Movement) return;

	if (IA_MoveAction)
		enhancedInput->BindAction(IA_MoveAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::MoveAction);

	if (IA_LookAction)
		enhancedInput->BindAction(IA_LookAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::LookAction);

	if (IA_DodgeAction)
		enhancedInput->BindAction(IA_DodgeAction, ETriggerEvent::Started, Movement, &UCMovementComponent::Dodge);

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

	if(IA_SKill_E)
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
}

