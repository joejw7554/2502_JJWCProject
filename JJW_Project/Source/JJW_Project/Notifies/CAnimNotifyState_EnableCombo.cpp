#include "CAnimNotifyState_EnableCombo.h"
#include "Player/CPlayer.h"
#include "Components/CWeaponComponent.h"

FString UCAnimNotifyState_EnableCombo::GetNotifyName_Implementation() const
{
	return "EnableCombo";
}

void UCAnimNotifyState_EnableCombo::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACPlayer* owner =Cast<ACPlayer>(MeshComp->GetOwner());
	if (!owner) return;

	UCWeaponComponent* weaponComp = owner->GetComponentByClass<UCWeaponComponent>();
	
}

void UCAnimNotifyState_EnableCombo::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACPlayer* owner = Cast<ACPlayer>(MeshComp->GetOwner());
	if (!owner) return;

	UCWeaponComponent* weaponComp = owner->GetComponentByClass<UCWeaponComponent>();
}
