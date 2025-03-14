#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "CWeaponBase.h"
#include "CWeaponStructure.h"
#include "CSkillStructure.h"

#include "CWeaponAsset.generated.h"
UCLASS()
class JJW_PROJECT_API UCWeaponAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	FORCEINLINE EWeaponType GetWeaponType() { return WeaponType; }
	FORCEINLINE TSubclassOf<ACWeaponBase> GetWeaponClass() { return WeaponClass; }
	FORCEINLINE FEquipmentData GetEquipmentData() { return EquipmentData; }
	FORCEINLINE FWeaponSkillSet& GetWeaponSkillSet() { return WeaponSkillSet; }

	FORCEINLINE ACWeaponBase* GetWeapon() { return  Weapon; }

	FORCEINLINE void SetWeapon(ACWeaponBase* InWeapon) { Weapon = InWeapon; }

private:
	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType = EWeaponType::Max;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACWeaponBase> WeaponClass;

	UPROPERTY(VisibleAnywhere)
	ACWeaponBase* Weapon;

	UPROPERTY(EditAnywhere, Category = "Equipment")
	FEquipmentData EquipmentData;

	UPROPERTY(EditAnywhere, Category = "Skills")
	FWeaponSkillSet WeaponSkillSet;
};
