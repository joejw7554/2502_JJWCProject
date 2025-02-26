#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSkillComponent.generated.h"


USTRUCT()
struct FSkillSet
{
	GENERATED_BODY()

	FName Name;
	class UAnimMontage* AttackMontage;
	float AttackMontage_PlayRate = 1.25f;
	float Damage = 10;
};

UCLASS()
class JJW_PROJECT_API UCSkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCSkillComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly)
	class UAnimMontage* BaseAttckCombo;

	UPROPERTY(EditDefaultsOnly, Category="Skill Property")
	TArray<FSkillSet> SkillList;
};
