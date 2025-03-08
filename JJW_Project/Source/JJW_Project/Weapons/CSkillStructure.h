#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSkillStructure.generated.h"


UENUM()
enum class ESkillKey : uint8
{
	Attack = 0, Skill1, Skill2, Skill3, Skill4,
};

USTRUCT()
struct FSkillData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	class UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere)
	float Attack_PlayRate = 1.25f;

	UPROPERTY(EditAnywhere)
	float AttackDamage = 10;

	UPROPERTY(EditAnywhere)
	bool bCanMove = false;

	UPROPERTY(EditAnywhere)
	bool bCanRotate = true;
};

USTRUCT()
struct FWeaponSkillSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Skills")
	TMap<ESkillKey, FSkillData> Skills;
};


UCLASS()
class JJW_PROJECT_API UCSkillStructure : public UObject
{
	GENERATED_BODY()
	
};
