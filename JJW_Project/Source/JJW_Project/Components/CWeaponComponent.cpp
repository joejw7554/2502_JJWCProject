#include "CWeaponComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "../Weapons/CWeaponAsset.h"
#include "GameFramework/Character.h"

UCWeaponComponent::UCWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;

	for (UCWeaponAsset* asset : WeaponAssets)
	{
		asset->InitializeWeaponAsset(OwnerCharacter);
	}

}

UCWeaponAsset* UCWeaponComponent::GetWeaponAsset(EWeaponType InType)
{
	for (UCWeaponAsset* asset : WeaponAssets)
	{
		if (InType == asset->GetWeaponType())
			return asset;
	}
	return nullptr;
}

UCEquipment* UCWeaponComponent::GetEquipment()
{
	UCEquipment* equipment = GetWeaponAsset(CurrentWeaponType)->GetEquipment();
	if (!equipment) return nullptr;

	return equipment;
}

ACWeaponBase* UCWeaponComponent::GetWeapon()
{
	ACWeaponBase* weapon = GetWeaponAsset(CurrentWeaponType)->GetWeapon();
	if (!weapon) return nullptr;

	return weapon;
}

void UCWeaponComponent::SetKatanaMode()
{
	SetMode(EWeaponType::Katana);
}



void UCWeaponComponent::SetMode(EWeaponType InType)
{
	if (CurrentWeaponType == InType)
	{
		//UnArmed
		ChangeState(EStateType::UnArmed);
	}
	else if (IsUnArmed())
	{
		//asset->GetEquipment()->Equip()
		//ChangeWeaponType();
		ChangeState(EStateType::Armed);
	}

	UCWeaponAsset* asset = GetWeaponAsset(InType);
	if (asset)
	{
		//asset->GetEquipment()->Equip();
		ChangeWeaponType(InType);
		ChangeState(EStateType::Armed);
	}
}

void UCWeaponComponent::ChangeWeaponType(EWeaponType InType)
{

}

void UCWeaponComponent::ChangeState(EStateType InType)
{
	CurrentState = InType;
}


