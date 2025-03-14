#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CMovementComponent.generated.h"


UCLASS()
class JJW_PROJECT_API UCMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCMovementComponent();
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;


public:
	void LookAction(const struct FInputActionValue& Value);
	void SprintAction(const struct FInputActionValue& Value);
	void MoveAction(const struct FInputActionValue& Value);
	void Dodge();

	void EnableControlRotation();
	void DisableControlRotation();

	FORCEINLINE void EnableMovement() { bCanMove = true; }
	FORCEINLINE void DisableMovment() { bCanMove = false; }
	FORCEINLINE bool CanMove() { return bCanMove; }

	void SetWalkMode();
	void SetSprintMode();

private:
	void SetMoveSpeed(float Value);

	bool IsArrivedAtDestination(FVector CurrentLocation, FVector TargetLocation);
	void MoveToDestination();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Camera Property")
	FVector2D PitchAngleLimit = FVector2D(-30, +30);

	UPROPERTY(EditDefaultsOnly, Category = "Movement Property")
	float WalkSpeed = 600.f;

	UPROPERTY(EditDefaultsOnly, Category = "Movement Property")
	float SprintSpeed = 1000.f;


	////////Montage
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	class UAnimMontage* AnimMontage_Dodge;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	float PlayRate_Dodge = 1.5f;


private:
	ACharacter* OwnerCharacter;

	APlayerController* PlayerController;

	//Montage
private:
	bool bCanMove = true;
	bool bIsRootMotionMoving = false;

	FVector LastInputLocation;

	float Tolerance = 40.f;

	

};
