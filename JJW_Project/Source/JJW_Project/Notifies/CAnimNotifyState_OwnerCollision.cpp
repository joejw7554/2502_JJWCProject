#include "Notifies/CAnimNotifyState_OwnerCollision.h"

FString UCAnimNotifyState_OwnerCollision::GetNotifyName_Implementation() const
{
	return "OnOffOwnerCollision";
}

void UCAnimNotifyState_OwnerCollision::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
}

void UCAnimNotifyState_OwnerCollision::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);


}


