#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
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
	void MoveAction(const struct FInputActionValue& Value);
	void Dodge();

	void RotateActorToCusorDirection();

	//void EnableControlRotation();
	void DisableControlRotation();

	FORCEINLINE FRotator GetCursorTargetRotation() { return CursorTargetRotation; }

	FORCEINLINE void EnableMovement() { bCanMove = true; }
	FORCEINLINE void DisableMovment() { bCanMove = false; }
	FORCEINLINE bool CanMove() { return bCanMove; }
	FORCEINLINE float GetMaxWalkSpeed() { return OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed; }

	FORCEINLINE void SetWalkMode() { SetMoveSpeed(WalkSpeed); }
	FORCEINLINE void SetBueffedWalkSpeed(float InValue) { SetMoveSpeed(InValue); }

private:
	FORCEINLINE void SetMoveSpeed(float Value) { OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed = Value; }

	bool IsArrivedAtDestination(FVector CurrentLocation, FVector TargetLocation);
	void MoveToDestination();

	void CalculateCursorDirection();

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
	FRotator CursorTargetRotation;

	bool bCanMove = true;
	bool bIsRootMotionMoving = false;

	FVector LastInputLocation;

	float Tolerance = 40.f;

	

};
