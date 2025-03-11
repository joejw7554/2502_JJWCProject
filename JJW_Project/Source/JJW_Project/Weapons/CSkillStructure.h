#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSkillStructure.generated.h"


UENUM()
enum class ESkillKey : uint8
{
	BasicCombo = 0, Q, W, E, R,
};

USTRUCT()
struct FSkillData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	class UAnimMontage* Montage;

	UPROPERTY(EditAnywhere)
	float PlayRate = 1.25f;

	UPROPERTY(EditAnywhere)
	float BaseDamage = 10;

	UPROPERTY(EditAnywhere)
	bool bCanMove = false;

	UPROPERTY(EditAnywhere)
	bool bCanRotate = true;

	UPROPERTY(EditAnywhere)
	TArray<float> SectionDamageMultiplier;
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
