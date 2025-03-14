#include "CAnimNotifyState_EnableCombo.h"
#include "Player/CPlayer.h"
#include "Components/CWeaponComponent.h"
#include "GameFramework/Character.h"

FString UCAnimNotifyState_EnableCombo::GetNotifyName_Implementation() const
{
	return "EnableCombo";
}

void UCAnimNotifyState_EnableCombo::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACharacter* ownerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	if (!ownerCharacter) return;

	UCWeaponComponent* weaponComp = ownerCharacter->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;

	weaponComp->SetEnableCombo();
}

void UCAnimNotifyState_EnableCombo::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACharacter* ownerCharacter = Cast<ACharacter>(MeshComp->GetOwner());

	if (!ownerCharacter) return;

	UCWeaponComponent* weaponComp = ownerCharacter->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;

	weaponComp->SetDisableCombo();
}
