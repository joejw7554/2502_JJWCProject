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

	WeaponOwner = GetOwner();

	if (WeaponOwner)
		SpawnWeapons();



}

void UCWeaponComponent::SpawnWeapons()
{
	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	params.Owner = WeaponOwner;

	for (TSubclassOf<ACWeaponBase> weaponClass : WeaponClassToSpawn)
	{
		if (weaponClass)
		{
			GetWorld()->SpawnActor<ACWeaponBase>(weaponClass, params);
		}
	}
}


void UCWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

