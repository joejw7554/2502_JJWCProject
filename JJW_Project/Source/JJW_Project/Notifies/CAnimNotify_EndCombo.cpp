#include "Notifies/CAnimNotify_EndCombo.h"
#include "Components/CWeaponComponent.h"
#include "GameFramework/Character.h"

FString UCAnimNotify_EndCombo::GetNotifyName_Implementation() const
{
	return "End Combo";
}

void UCAnimNotify_EndCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	if (!OwnerCharacter) return;

	UCWeaponComponent* weaponComp = OwnerCharacter->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp)return;

	weaponComp->ResetComboIndex();
}
