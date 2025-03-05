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
	FORCEINLINE EWeaponType GetWeaponType() { return WeaponType; }
	FORCEINLINE FEquipmentData GetEquipmentData() { return EquipmentData; }

	//무기타입
	//실제 무기 BP
	//EquipmentData

private:
	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType = EWeaponType::Max;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ACWeaponBase> Weapon;

	UPROPERTY(EditAnywhere)
	FEquipmentData EquipmentData;

private:
};
