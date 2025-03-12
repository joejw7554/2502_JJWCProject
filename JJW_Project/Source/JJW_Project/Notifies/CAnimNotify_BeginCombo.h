#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CAnimNotify_BeginCombo.generated.h"

UCLASS()
class JJW_PROJECT_API UCAnimNotify_BeginCombo : public UAnimNotify
{
	GENERATED_BODY()

private:
	FString GetNotifyName_Implementation() const;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	
};
