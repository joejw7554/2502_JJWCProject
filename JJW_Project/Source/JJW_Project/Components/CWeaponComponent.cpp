#include "CWeaponComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "GameFramework/Character.h"

UCWeaponComponent::UCWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACharacter>(GetOwner());
	if (!Owner) return;

	SpawnWeapons();
}

void UCWeaponComponent::SpawnWeapons()
{
	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	params.Owner = Owner;

	for (TSubclassOf<ACWeaponBase> weaponClass : WeaponClassToSpawn)
	{
		if (weaponClass)
		{
			ACWeaponBase* newWeapon= GetWorld()->SpawnActor<ACWeaponBase>(weaponClass, params);
			ActiveWeapons.AddUnique(newWeapon);
		}
	}
}

void UCWeaponComponent::EquipWeapon(EWeaponType InPrevType, EWeaponType InNewType)
{
	EWeaponType prev = InPrevType;

	if (prev == InNewType)
	{
		//GetCurrentWeapon->Unequip
		CurrentWeaponType = EWeaponType::None;
		return;
	}
	else if(prev==EWeaponType::None)
	{
		CurrentWeaponType = InNewType;
		GetCurrentWeapon()->Equip();
		return;
	}
	
	//GetCurrentWeapon()->UnEquip() //UnEquipPrev
	CurrentWeaponType = InNewType;

	if (GetCurrentWeapon())
		GetCurrentWeapon()->Equip();
}


void UCWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

ACWeaponBase* UCWeaponComponent::GetCurrentWeapon()
{
	return ActiveWeapons[(uint8)CurrentWeaponType];
}

void UCWeaponComponent::SetKatanaMode()
{
	EquipWeapon(CurrentWeaponType, EWeaponType::Katana);
}

