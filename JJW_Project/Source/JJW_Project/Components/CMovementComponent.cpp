#include "CMovementComponent.h"
#include "InputActionValue.h"
#include "../Player/CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"


UCMovementComponent::UCMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UCMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACPlayer>(GetOwner());

	if (!Owner) return;

	APlayerController* playerController = Owner->GetController<APlayerController>();

	if (!playerController) return;

	playerController->PlayerCameraManager->ViewPitchMin = PitchAngleLimit.X;
	playerController->PlayerCameraManager->ViewPitchMax = PitchAngleLimit.Y;

	Owner->GetCharacterMovement()->RotationRate = FRotator(0, 540.f, 0);
}

void UCMovementComponent::MoveAction(const FInputActionValue& Value)
{
	FVector2D val = Value.Get<FVector2D>();

	FRotator yawRotator = FRotator(0.f, Owner->GetControlRotation().Yaw, 0.f);
	FVector forward = FQuat(yawRotator).GetForwardVector();
	FVector right = FQuat(yawRotator).GetRightVector();

	Owner->AddMovementInput(forward, val.Y);
	Owner->AddMovementInput(right, val.X);
}

void UCMovementComponent::LookAction(const FInputActionValue& Value)
{
	FVector2D val = Value.Get<FVector2D>();

	Owner->AddControllerYawInput(val.X);
	Owner->AddControllerPitchInput(-val.Y);
}

void UCMovementComponent::SprintAction(const FInputActionValue& Value)
{
	bool bPressed = Value.Get<bool>();

	if (bPressed)
		SetSprintMode();
	else
		SetWalkMode();
}

void UCMovementComponent::EnableControlRotation()
{
	Owner->GetCharacterMovement()->bOrientRotationToMovement = false;
	Owner->bUseControllerRotationYaw = true;
}

void UCMovementComponent::DisableControlRotation()
{
	Owner->GetCharacterMovement()->bOrientRotationToMovement = true;
	Owner->bUseControllerRotationYaw = false;
}

void UCMovementComponent::SetWalkMode()
{
	SetMoveSpeed(WalkSpeed);
}

void UCMovementComponent::SetSprintMode()
{
	SetMoveSpeed(SprintSpeed);
}

void UCMovementComponent::SetMoveSpeed(float Value)
{
	Owner->GetCharacterMovement()->MaxWalkSpeed = Value;
}

