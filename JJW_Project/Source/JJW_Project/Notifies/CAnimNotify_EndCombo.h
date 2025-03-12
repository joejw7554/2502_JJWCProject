#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CAnimNotify_EndCombo.generated.h"

UCLASS()
class JJW_PROJECT_API UCAnimNotify_EndCombo : public UAnimNotify
{
	GENERATED_BODY()

private:
	FString GetNotifyName_Implementation() const;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	
};
