#include "CWeaponAsset.h"
#include "CEquipment.h"
#include "CWeaponBase.h"
#include "GameFramework/Character.h"

UCWeaponAsset::UCWeaponAsset()
{
	//Defualt Value for preventing Null
	WeaponType = EWeaponType::Max;
	EquipmentClass = UCEquipment::StaticClass(); 
	WeaponClass = ACWeaponBase::StaticClass();
}

void UCWeaponAsset::InitializeWeaponAsset(ACharacter* InOwner)
{
	if (EquipmentClass)
	{
		Equipment = NewObject<UCEquipment>(this, EquipmentClass);
		Equipment->InitializeEquipmentData(InOwner, EquipmentData);
	}

	if (WeaponClass)
	{
		FActorSpawnParameters params;
		params.Owner = InOwner;
		params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Weapon = InOwner->GetWorld()->SpawnActor<ACWeaponBase>(WeaponClass, params);
		Weapon->InitializeWeapon(EquipmentData);
	}

}
