#include "CEquipment.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"


void UCEquipment::InitializeEquipmentData(ACharacter* InOwner, const FEquipmentData& InData)
{
	OwnerCharacter = InOwner;
	Data = InData;
}

void UCEquipment::Equip()
{
	OwnerCharacter->PlayAnimMontage(Data.EquipMontage, Data.Equip_PlayRate);
}

void UCEquipment::UnEquip()
{
	//Not sure if I should implement or not
}
