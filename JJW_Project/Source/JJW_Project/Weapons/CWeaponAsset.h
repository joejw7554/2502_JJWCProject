#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CWeaponStructure.h"
#include "CWeaponAsset.generated.h"

UCLASS()
class JJW_PROJECT_API UCWeaponAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UCWeaponAsset();

public:
	void InitializeWeaponAsset(ACharacter* InOwner);

	EWeaponType GetWeaponType() { return WeaponType; }
	class UCEquipment* GetEquipment() { return Equipment? Equipment: nullptr; }

private:
	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType = EWeaponType::Max;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ACWeaponBase> WeaponClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCEquipment>EquipmentClass;

	UPROPERTY(EditAnywhere)
	 FEquipmentData EquipmentData;

private:
	UPROPERTY()
	class UCEquipment* Equipment;

	UPROPERTY()
	class ACWeaponBase* Weapon;
};
