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

protected:
	virtual void BeginPlay() override;

public:
	void MoveAction(const struct FInputActionValue& Value);
	void LookAction(const FInputActionValue& Value);
	void SprintAction(const FInputActionValue& Value);
	void Dodge();

	void EnableControlRotation();
	void DisableControlRotation();

	void SetWalkMode();
	void SetSprintMode();

private:
	void SetMoveSpeed(float Value);

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
	ACharacter* Owner;

	//Montage
private:
	

};
