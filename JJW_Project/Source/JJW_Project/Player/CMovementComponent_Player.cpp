#include "Player/CMovementComponent_Player.h"
#include "InputActionValue.h"
#include "../Player/CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCMovementComponent_Player::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CanMove() == true)
		MoveToDestination();

	CalculateCursorDirection();
}

void UCMovementComponent_Player::MoveToDestination()
{
	if (IsArrivedAtDestination(OwnerCharacter->GetActorLocation(), LastInputLocation))
		DisableMovment();

	if (!OwnerCharacter) return;
	FVector direction = (LastInputLocation - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	OwnerCharacter->AddMovementInput(direction, 1);
}

void UCMovementComponent_Player::CalculateCursorDirection()
{
	APlayerController* controller = Cast<APlayerController>(OwnerCharacter->GetController());
	if (!controller) return;

	FHitResult hitResult;
	controller->GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	FVector cursorDirection = (hitResult.ImpactPoint - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	FRotator cursorTowardRotation = FRotationMatrix::MakeFromXY(cursorDirection, FVector::UpVector).Rotator();
	cursorTowardRotation.Pitch = 0.f;
	cursorTowardRotation.Roll = 0.f;

	RotationToTarget = cursorTowardRotation;
}

bool UCMovementComponent_Player::IsArrivedAtDestination(FVector CurrentLocation, FVector TargetLocation)
{
	return FVector::DistXY(CurrentLocation, TargetLocation) < Tolerance;
}

void UCMovementComponent_Player::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACPlayer>(GetOwner());
	if (!OwnerCharacter) return;

	PlayerController = OwnerCharacter->GetController<APlayerController>();
	if (!PlayerController) return;

	PlayerController->bShowMouseCursor = true;
	OwnerCharacter->GetCharacterMovement()->RotationRate = FRotator(0, 540.f, 0);
}

void UCMovementComponent_Player::MoveAction(const FInputActionValue& Value)
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

void UCMovementComponent_Player::Dodge()
{
	if (!OwnerCharacter) return;

	if (OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;

	RotateActor(RotationToTarget);

	if (AnimMontage_Dodge)
		OwnerCharacter->PlayAnimMontage(AnimMontage_Dodge, PlayRate_Dodge);

	DisableMovment();
}

void UCMovementComponent_Player::DisableControlRotation()
{
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	OwnerCharacter->bUseControllerRotationYaw = false;
}