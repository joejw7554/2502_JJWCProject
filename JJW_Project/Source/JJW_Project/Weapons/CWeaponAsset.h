#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CWeaponStructure.h"
#include "CWeaponBase.h"
#include "CWeaponAsset.generated.h"

UCLASS()
class JJW_PROJECT_API UCWeaponAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	FORCEINLINE EWeaponType GetWeaponType() { return WeaponType; }
	FORCEINLINE TSubclassOf<ACWeaponBase> GetWeaponClass(){ return WeaponClass; }
	FORCEINLINE FEquipmentData GetEquipmentData() { return EquipmentData; }
	FORCEINLINE void SetWeapon(ACWeaponBase* InWeapon) { Weapon = InWeapon; }
	FORCEINLINE ACWeaponBase* GetWeapon(){ return  Weapon; }


	//무기타입
	//실제 무기 BP
	//EquipmentData

private:
	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType = EWeaponType::Max;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACWeaponBase> WeaponClass;

	UPROPERTY(EditAnywhere)
	ACWeaponBase* Weapon;

	UPROPERTY(EditAnywhere)
	FEquipmentData EquipmentData;
};
