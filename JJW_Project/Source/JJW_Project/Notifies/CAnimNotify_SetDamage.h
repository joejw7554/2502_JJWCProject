#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Weapons/CSkillStructure.h"
#include "CAnimNotify_SetDamage.generated.h"

UCLASS()
class JJW_PROJECT_API UCAnimNotify_SetDamage : public UAnimNotify
{
	GENERATED_BODY()

private:
	FString GetNotifyName_Implementation() const;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	UPROPERTY(EditAnywhere, Category="Modifier|Skill")
	ESkillKey SkillKey;

	UPROPERTY(EditAnywhere, Category = "Modifier|Skill")
	float DamageModifier = 1.f;
};
