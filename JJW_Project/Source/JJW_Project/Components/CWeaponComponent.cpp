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

void UCWeaponComponent::EquipWeapon()
{

}

void UCWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}



