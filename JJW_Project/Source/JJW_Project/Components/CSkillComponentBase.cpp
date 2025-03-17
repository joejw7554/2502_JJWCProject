#include "CSkillComponentBase.h"

#include "GameFramework/Character.h"

#include "Weapons/CWeaponBase.h"
#include "Weapons/CSkillStructure.h"
#include "CMovementComponent.h"

UCSkillComponentBase::UCSkillComponentBase()
{
}

void UCSkillComponentBase::BeginPlay()
{
	Super::BeginPlay();
}

void UCSkillComponentBase::PerformSkill(bool bEnableCombo, int8 InComboIndex,  ACharacter* InWeaponOwner)
{
	if (!SkillData) return;
	if (!InWeaponOwner)return;

	UAnimMontage* montage = SkillData->Montage;
	float playRate = SkillData->PlayRate;

	UAnimInstance* animInstance = InWeaponOwner->GetMesh()->GetAnimInstance();
	if (!animInstance) return;

	UCMovementComponent* movementComp = InWeaponOwner->GetComponentByClass<UCMovementComponent>();
	if (!movementComp) return;


	if (animInstance->Montage_IsPlaying(montage))
	{
		if (bEnableCombo)
		{
			FName nextSection = GetComboSectionName(InComboIndex);
			if (nextSection != NAME_None)
			{
				animInstance->Montage_JumpToSection(nextSection);
				movementComp->RotateActorToCusorDirection();

			}
		}
	}
	else
	{
		InWeaponOwner->PlayAnimMontage(montage, playRate);
		movementComp->RotateActorToCusorDirection();
	}

}

FName UCSkillComponentBase::GetComboSectionName(int32 comboIndex)
{
	switch (comboIndex)
	{
	case 2:
		return "Section2";
	case 3:
		return "Section3";
	case 4:
		return "Section4";
	case 5:
		return "Section5";
	default:
		return NAME_None;
	}
}

void UCSkillComponentBase::InitialzeSkillData(const FWeaponSkillSet* InSkillSet, ESkillKey InKey)
{
	if (InSkillSet)
	{
		const FSkillData* SkillDataPtr = InSkillSet->Skills.Find(InKey);

		if (SkillDataPtr)
			SkillData = SkillDataPtr;
		else
			UE_LOG(LogTemp, Warning, TEXT("UCSkillComponentBase:: NullFound"), SkillData->BaseDamage);
	}
}

