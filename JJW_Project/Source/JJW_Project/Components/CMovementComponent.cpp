#include "CMovementComponent.h"

UCMovementComponent::UCMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCMovementComponent::RotateActor(FRotator TargetRotation)
{
	OwnerCharacter->SetActorRotation(TargetRotation, ETeleportType::ResetPhysics);
}



