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

	CalculateCursorDirection();
}



void UCMovementComponent::MoveToDestination()
{
	if (IsArrivedAtDestination(OwnerCharacter->GetActorLocation(), LastInputLocation))
		DisableMovment();

	if (!OwnerCharacter) return;
	FVector direction = (LastInputLocation - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	OwnerCharacter->AddMovementInput(direction, 1);
}

void UCMovementComponent::CalculateCursorDirection()
{
	APlayerController* controller = Cast<APlayerController>(OwnerCharacter->GetController());
	if (!controller) return;

	FHitResult hitResult;
	controller->GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	FVector cursorDirection = (hitResult.ImpactPoint - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	FRotator cursorTowardRotation = FRotationMatrix::MakeFromXY(cursorDirection, FVector::UpVector).Rotator();
	cursorTowardRotation.Pitch = 0.f;
	cursorTowardRotation.Roll = 0.f;

	CursorTargetRotation = cursorTowardRotation;
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
	if (!OwnerCharacter) return;

	if (OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;

	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!player) return;

	RotateActorToCusorDirection();

	if (AnimMontage_Dodge)
			OwnerCharacter->PlayAnimMontage(AnimMontage_Dodge, PlayRate_Dodge);

	DisableMovment();
}

void UCMovementComponent::RotateActorToCusorDirection()
{
	FRotator RotateTarget = CursorTargetRotation;
	OwnerCharacter->SetActorRotation(RotateTarget, ETeleportType::ResetPhysics);
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

