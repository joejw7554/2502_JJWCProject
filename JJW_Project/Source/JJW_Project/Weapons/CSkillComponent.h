#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CWeaponStructure.h"
#include "CSkillComponent.generated.h"




UCLASS()
class JJW_PROJECT_API UCSkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCSkillComponent();

protected:
	virtual void BeginPlay() override;

public:
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void PlayBaseAttackCombo();

private:
	
};
