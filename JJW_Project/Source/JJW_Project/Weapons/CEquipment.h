#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWeaponStructure.h"
#include "CEquipment.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWeaponAttach);


UCLASS()
class JJW_PROJECT_API UCEquipment : public UObject
{
	GENERATED_BODY()

public:
	void InitializeEquipmentData(ACharacter* InOwner, const FEquipmentData& InData);

private:
	class ACharacter* OwnerCharacter;

public:
	void CommonEquip();

	UFUNCTION(BlueprintNativeEvent)
	void Begin_Equip();
	void Begin_Equip_Implementation();


	UFUNCTION(BlueprintNativeEvent)
	void End_Equip();
	void End_Equip_Implementation();

public:
	FWeaponAttach OnWeaponAttach;

private:
	FEquipmentData Data;
};
