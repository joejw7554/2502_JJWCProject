#pragma once

#include "CoreMinimal.h"
#include "Components/CMovementComponent.h"
#include "CMovementComponent_Player.generated.h"

UCLASS()
class JJW_PROJECT_API UCMovementComponent_Player : public UCMovementComponent
{
	GENERATED_BODY()
	

protected:
	virtual void BeginPlay() override;
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	virtual void MoveAction(const struct FInputActionValue& Value);
	void Dodge();

	void DisableControlRotation();


	FORCEINLINE float GetMaxWalkSpeed() { return OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed; }

	FORCEINLINE void SetWalkMode() { SetMoveSpeed(WalkSpeed); }
	FORCEINLINE void SetBueffedWalkSpeed(float InValue) { SetMoveSpeed(InValue); }

private:
	FORCEINLINE void SetMoveSpeed(float Value) { OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed = Value; }

	bool IsArrivedAtDestination(FVector CurrentLocation, FVector TargetLocation);
	void MoveToDestination();

	void CalculateCursorDirection();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Movement Property")
	float WalkSpeed = 600.f;

	////////Montage
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	class UAnimMontage* AnimMontage_Dodge;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	float PlayRate_Dodge = 1.5f;

private:
	APlayerController* PlayerController;

	//Montage
private:
	

	bool bIsRootMotionMoving = false;

	FVector LastInputLocation;

	float Tolerance = 40.f;
};
