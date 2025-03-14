#include "CAnimNotifyState_Collision.h"

#include "Components/CWeaponComponent.h"
#include "Weapons/CWeaponBase.h"

FString UCAnimNotifyState_Collision::GetNotifyName_Implementation() const
{
	return "Collision";
}

void UCAnimNotifyState_Collision::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	UCWeaponComponent* weaponComp= MeshComp->GetOwner()->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;

	weaponComp->EnableWeaponCollision();

}

void UCAnimNotifyState_Collision::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);


	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	UCWeaponComponent* weaponComp = MeshComp->GetOwner()->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;

	weaponComp->DisableWeaponCollision();
}
