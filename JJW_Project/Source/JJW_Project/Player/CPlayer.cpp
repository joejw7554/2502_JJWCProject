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

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

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

	InitializePlayerEnhnacedInput();

	if (Movement)
		Movement->DisableControlRotation();

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

	if (IA_SprintAction)
		enhancedInput->BindAction(IA_SprintAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::SprintAction);

	if (IA_DodgeAction)
		enhancedInput->BindAction(IA_DodgeAction, ETriggerEvent::Started, Movement, &UCMovementComponent::Dodge);

	if (IA_KatanaAction)
		enhancedInput->BindAction(IA_KatanaAction, ETriggerEvent::Started, Weapon, &UCWeaponComponent::SetKatanaMode);

	if (IA_TestWeapon)
		enhancedInput->BindAction(IA_TestWeapon, ETriggerEvent::Started, Weapon, &UCWeaponComponent::TestWeaponMode);

	if (IA_BasicAttackAction)
		enhancedInput->BindAction(IA_BasicAttackAction, ETriggerEvent::Started, Weapon, &UCWeaponComponent::DoBasicAttack);

}

