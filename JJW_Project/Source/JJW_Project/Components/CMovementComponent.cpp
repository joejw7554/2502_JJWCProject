#include "CMovementComponent.h"
#include "InputActionValue.h"
#include "../Player/CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"


UCMovementComponent::UCMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!OwnerCharacter) return;

	if (CheckDistance() &&bCanMove)
		MoveToDestination();
}

void UCMovementComponent::MoveToDestination()
{
	FVector direction = (LastInputLocation - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	OwnerCharacter->AddMovementInput(direction, 1);
}

bool UCMovementComponent::CheckDistance()
{
	return FVector::Dist(OwnerCharacter->GetActorLocation(), LastInputLocation) > Tolerance;
}


void UCMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACPlayer>(GetOwner());

	if (!OwnerCharacter) return;

	PlayerController = OwnerCharacter->GetController<APlayerController>();

	if (!PlayerController) return;

	PlayerController->PlayerCameraManager->ViewPitchMin = PitchAngleLimit.X;
	PlayerController->PlayerCameraManager->ViewPitchMax = PitchAngleLimit.Y;
	PlayerController->bShowMouseCursor = true;

	OwnerCharacter->GetCharacterMovement()->RotationRate = FRotator(0, 540.f, 0);
}

void UCMovementComponent::MoveAction(const FInputActionValue& Value)
{
	if (!PlayerController) return;
	if (!OwnerCharacter) return;

	FHitResult hitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, true, hitResult);

	LastInputLocation = hitResult.Location;
}

void UCMovementComponent::LookAction(const FInputActionValue& Value)
{
	FVector2D val = Value.Get<FVector2D>();

	OwnerCharacter->AddControllerYawInput(val.X);
	OwnerCharacter->AddControllerPitchInput(-val.Y);
}

void UCMovementComponent::SprintAction(const FInputActionValue& Value)
{
	bool bPressed = Value.Get<bool>();

	if (bPressed)
		SetSprintMode();
	else
		SetWalkMode();
}


void UCMovementComponent::Dodge()
{
	OwnerCharacter->SetActorRotation(OwnerCharacter->GetLastMovementInputVector().Rotation(), ETeleportType::ResetPhysics);

	if (AnimMontage_Dodge)
		if (!OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying())
			OwnerCharacter->PlayAnimMontage(AnimMontage_Dodge, PlayRate_Dodge);
}

void UCMovementComponent::EnableControlRotation()
{
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
	OwnerCharacter->bUseControllerRotationYaw = true;
}

void UCMovementComponent::DisableControlRotation()
{
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	OwnerCharacter->bUseControllerRotationYaw = false;
}

void UCMovementComponent::EnableMovement()
{
	bCanMove = true;
}

void UCMovementComponent::DisableMovment()
{
	bCanMove = false;
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
	OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed = Value;
}

