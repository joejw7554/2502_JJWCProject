#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CWeaponBase.generated.h"

UCLASS(Abstract)
class JJW_PROJECT_API ACWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	ACWeaponBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void InitializeWeapon(const struct FEquipmentData& InData)
	{}

	virtual void ShowWeapon() {}
	virtual void HideWeapon() {}

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

protected:
	class ACharacter* OwnerCharacter;

};
