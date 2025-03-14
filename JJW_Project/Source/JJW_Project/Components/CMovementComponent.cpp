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

	if (bCanMove == true)
		MoveToDestination();

	
}

void UCMovementComponent::MoveToDestination()
{
	if (IsArrivedAtDestination(OwnerCharacter->GetActorLocation(), LastInputLocation))
		DisableMovment();

	if (!OwnerCharacter) return;
	FVector direction = (LastInputLocation - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	OwnerCharacter->AddMovementInput(direction, 1);
}

bool UCMovementComponent::IsArrivedAtDestination(FVector CurrentLocation, FVector TargetLocation)
{
	return FVector::DistXY(CurrentLocation, TargetLocation) < Tolerance;
}


void UCMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACPlayer>(GetOwner());

	if (!OwnerCharacter) return;

	PlayerController = OwnerCharacter->GetController<APlayerController>();

	if (!PlayerController) return;

	PlayerController->bShowMouseCursor = true;
	OwnerCharacter->GetCharacterMovement()->RotationRate = FRotator(0, 540.f, 0);
}

void UCMovementComponent::MoveAction(const FInputActionValue& Value)
{
	if (!PlayerController) return;
	if (!OwnerCharacter) return;
	if (!PlayerController) return;
	if (OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;

	FHitResult hitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	LastInputLocation = hitResult.Location;
	EnableMovement();
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
	if (OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;

	OwnerCharacter->SetActorRotation(OwnerCharacter->GetLastMovementInputVector().Rotation(), ETeleportType::ResetPhysics);

	if (AnimMontage_Dodge)
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

