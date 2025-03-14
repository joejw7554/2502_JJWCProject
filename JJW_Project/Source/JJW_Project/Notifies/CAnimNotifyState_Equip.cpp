#include "CAnimNotifyState_Equip.h"
#include "../Components/CWeaponComponent.h"

FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
{
	return FString("Equip");
}

void UCAnimNotifyState_Equip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	UCWeaponComponent* weaponComp= MeshComp->GetOwner()->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;

	
	weaponComp->Begin_Equip();
}

void UCAnimNotifyState_Equip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	UCWeaponComponent* weaponComp = MeshComp->GetOwner()->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;


	weaponComp->End_Equip();
}
