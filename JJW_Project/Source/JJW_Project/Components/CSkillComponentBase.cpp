#include "CSkillComponentBase.h"

#include "GameFramework/Character.h"

#include "Weapons/CWeaponBase.h"
#include "Weapons/CSkillStructure.h"

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
	
	APlayerController* controller = Cast<APlayerController>(InWeaponOwner->GetController());
	if (!controller) return;

	FHitResult hitResult;
	controller->GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	FVector lookDirection = (hitResult.ImpactPoint - InWeaponOwner->GetActorLocation()).GetSafeNormal();
	FRotator lookRotation = FRotationMatrix::MakeFromXY(lookDirection, FVector::UpVector).Rotator();
	lookRotation.Pitch = 0.f;
	lookRotation.Roll = 0.f;

	UAnimMontage* montage = SkillData->Montage;
	float playRate = SkillData->PlayRate;

	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner()->Owner);
	UAnimInstance* animInstance = ownerCharacter->GetMesh()->GetAnimInstance();
	if (!animInstance) return;


	if (animInstance->Montage_IsPlaying(montage))
	{
		if (bEnableCombo)
		{
			FName nextSection = GetComboSectionName(InComboIndex);
			if (nextSection != NAME_None)
			{
				animInstance->Montage_JumpToSection(nextSection);
				InWeaponOwner->SetActorRotation(lookRotation);
			}
		}
	}
	else
	{
		ownerCharacter->PlayAnimMontage(montage, playRate);
		InWeaponOwner->SetActorRotation(lookRotation);
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

