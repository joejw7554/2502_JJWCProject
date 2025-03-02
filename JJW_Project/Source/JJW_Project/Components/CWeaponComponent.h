#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "CWeaponComponent.generated.h"


UENUM()
enum class EStateType :uint8
{
	UnArmed=0, Armed
};

UCLASS()
class JJW_PROJECT_API UCWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCWeaponComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

public:
	void EquipWeapon();

protected:

private:
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TArray<class UCWeaponAsset*> WeaponAssets;

private:
	ACharacter* OwnerCharacter;

	EStateType CurrentState= EStateType::UnArmed;
};
