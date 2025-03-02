#include "CWeaponAsset.h"
#include "CEquipment.h"
#include "CWeaponBase.h"

UCWeaponAsset::UCWeaponAsset()
{
	//Defualt Value for preventing Null
	WeaponType = EWeaponType::Max;
	EquipmentClass = UCEquipment::StaticClass(); 
	EquipmentClass = ACWeaponBase::StaticClass();
}

void UCWeaponAsset::InitializeWeaponAsset(ACharacter* InOwner)
{
	if (WeaponClass)
	{

	}

	if (EquipmentClass)
	{
		Equipment = NewObject<UCEquipment>(this, EquipmentClass);
		Equipment->InitializeEquipmentData(InOwner, EquipmentData);
	}

}
