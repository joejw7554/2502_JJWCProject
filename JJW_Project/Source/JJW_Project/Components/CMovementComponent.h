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
	void Move(const struct FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void EnableControlRotation();
	void DisableControlRotation();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Camera Property")
	FVector2D PitchAngleLimit = FVector2D(-60, 60);

private:
	ACharacter* Owner;


};
