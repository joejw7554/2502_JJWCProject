#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Weapons/CSkillStructure.h"
#include "CSkillComponentBase.generated.h"


UCLASS()
class JJW_PROJECT_API UCSkillComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCSkillComponentBase();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE const FSkillData* GetSkillData() { return SkillData; } 

	////////
public:
	void PerformSkill(bool bEnableCombo, int8 InComboIndex);
private:
	FName GetComboSectionName(int32 comboIndex);


public:
	virtual void InitialzeSkillData(const FWeaponSkillSet* InSkillSet, ESkillKey InKey);

protected:
	const FSkillData* SkillData;

	class ACWeaponBase* ComponentOwner;
};
