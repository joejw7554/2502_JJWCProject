#include "Notifies/CAnimNotify_EndCombo.h"

FString UCAnimNotify_EndCombo::GetNotifyName_Implementation() const
{
	return "End Combo";
}

void UCAnimNotify_EndCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
}
