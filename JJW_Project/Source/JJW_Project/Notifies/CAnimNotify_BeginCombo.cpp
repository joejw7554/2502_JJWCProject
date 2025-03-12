#include "CAnimNotify_BeginCombo.h"
#include "Components/CWeaponComponent.h"
#include "GameFramework/Character.h"

FString UCAnimNotify_BeginCombo::GetNotifyName_Implementation() const
{
	return "Begin Combo";
}

void UCAnimNotify_BeginCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	if (!OwnerCharacter) return;

	UCWeaponComponent* weaponComp = OwnerCharacter->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp)return;

	weaponComp->IncreasementComboIndex();
}
