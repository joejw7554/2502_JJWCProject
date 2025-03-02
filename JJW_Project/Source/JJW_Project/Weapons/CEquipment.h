#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWeaponStructure.h"
#include "CEquipment.generated.h"

UCLASS()
class JJW_PROJECT_API UCEquipment : public UObject
{
	GENERATED_BODY()

public:
	void InitializeEquipmentData(ACharacter* InOwner, const FEquipmentData& InData);

private:
	class ACharacter* OwnerCharacter;

public:
	void Equip();
	void UnEquip();

private:
	FEquipmentData Data;
};
