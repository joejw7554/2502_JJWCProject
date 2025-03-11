#include "CAnimNotify_BeginCombo.h"

FString UCAnimNotify_BeginCombo::GetNotifyName_Implementation() const
{
	return "Begin Combo";
}

void UCAnimNotify_BeginCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
}
