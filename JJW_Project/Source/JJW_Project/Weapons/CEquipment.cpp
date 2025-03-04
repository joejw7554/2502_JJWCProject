#include "CEquipment.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "../Components/CMovementComponent.h"


void UCEquipment::InitializeEquipmentData(ACharacter* InOwner, const FEquipmentData& InData)
{
	OwnerCharacter = InOwner;
	Data = InData;
}

void UCEquipment::CommonEquip()
{
	UCMovementComponent* Movement = OwnerCharacter->GetComponentByClass<UCMovementComponent>();
	if (!Movement) return;

	if (!Data.bCanMove)
		Movement->DisableMovment();

	if (!Data.bCanRotate)
		Movement->DisableControlRotation();

}

void UCEquipment::Begin_Equip_Implementation()
{
	OwnerCharacter->PlayAnimMontage(Data.EquipMontage, Data.Equip_PlayRate);
	if (OnWeaponAttach.IsBound())
		OnWeaponAttach.Broadcast();
}

void UCEquipment::End_Equip_Implementation()
{
	UCMovementComponent* Movement = OwnerCharacter->GetComponentByClass<UCMovementComponent>();

	Movement->EnableMovement();
	Movement->EnableControlRotation();
}

