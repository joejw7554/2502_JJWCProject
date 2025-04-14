#include "CMovementComponent.h"
#include "InputActionValue.h"
#include "../Player/CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"


UCMovementComponent::UCMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

//p
void UCMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (bCanMove == true)
		MoveToDestination();

	CalculateCursorDirection();
}

//p
void UCMovementComponent::MoveToDestination()
{
	if (IsArrivedAtDestination(OwnerCharacter->GetActorLocation(), LastInputLocation))
		DisableMovment();

	if (!OwnerCharacter) return;
	FVector direction = (LastInputLocation - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	OwnerCharacter->AddMovementInput(direction, 1);
}

//p
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

//player
bool UCMovementComponent::IsArrivedAtDestination(FVector CurrentLocation, FVector TargetLocation)
{
	return FVector::DistXY(CurrentLocation, TargetLocation) < Tolerance;
}

//p
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

//p
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

//Fixable
void UCMovementComponent::Dodge()
{
	if (!OwnerCharacter) return;

	if (OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;

	RotateActor();

	if (AnimMontage_Dodge)
			OwnerCharacter->PlayAnimMontage(AnimMontage_Dodge, PlayRate_Dodge);

	DisableMovment();
}

//p
void UCMovementComponent::RotateActor()
{
	FRotator RotateTarget = CursorTargetRotation;
	OwnerCharacter->SetActorRotation(RotateTarget, ETeleportType::ResetPhysics);
}

//?
void UCMovementComponent::DisableControlRotation()
{
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	OwnerCharacter->bUseControllerRotationYaw = false;
}

