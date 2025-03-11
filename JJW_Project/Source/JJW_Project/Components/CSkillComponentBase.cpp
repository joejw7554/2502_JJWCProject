#include "CSkillComponentBase.h"
#include "../Weapons/CWeaponBase.h"

UCSkillComponentBase::UCSkillComponentBase()
{
}

void UCSkillComponentBase::BeginPlay()
{
	Super::BeginPlay();

	ComponentOwner = Cast<ACWeaponBase>(GetOwner());
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
