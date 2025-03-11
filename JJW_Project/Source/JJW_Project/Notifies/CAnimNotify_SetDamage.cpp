#include "CAnimNotify_SetDamage.h"
#include "GameFramework/Character.h"
#include "Components/CWeaponComponent.h"
#include "Weapons/CWeaponBase.h"
#include "Weapons/CWeaponAsset.h"
#include "Weapons/CSkillStructure.h"

FString UCAnimNotify_SetDamage::GetNotifyName_Implementation() const
{
	return "Set Damage";
}

void UCAnimNotify_SetDamage::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);


	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACharacter* ownerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	if (!ownerCharacter) return;

	UCWeaponComponent* weaponComp= ownerCharacter->GetComponentByClass<UCWeaponComponent>();
	if (!weaponComp) return;

	UCWeaponAsset* currentWeaponAsset = weaponComp->GetWeaponAsset(weaponComp->GetCurrentWeaponType());
	if (!currentWeaponAsset) return;

	ACWeaponBase* weapon = currentWeaponAsset->GetWeapon();
	if (!weapon) return;

	FWeaponSkillSet weaponSkillSet = currentWeaponAsset->GetWeaponSkillSet();

	weapon->SetDamage(weaponSkillSet.Skills[SkillKey].BaseDamage*weaponSkillSet.Skills[SkillKey].SectionDamageMultiplier[SectionIndex]);

	UE_LOG(LogTemp, Warning, TEXT("Set Damage : %f"), weaponSkillSet.Skills[SkillKey].BaseDamage * weaponSkillSet.Skills[SkillKey].SectionDamageMultiplier[SectionIndex]);

}
