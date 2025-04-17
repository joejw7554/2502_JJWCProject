#include "Notifies/CAnimNotify_HitReactionEnd.h"
#include "CAnimNotify_HitReactionEnd.h"
#include "Enemy/CEnemyAnimInstance.h"
#include "GameFramework/Character.h"
#include "Enemy/CAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

FString UCAnimNotify_HitReactionEnd::GetNotifyName_Implementation() const
{
	return "Hit Reaction End";
}

void UCAnimNotify_HitReactionEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (!MeshComp) return;

	ACharacter* owner = Cast<ACharacter>(MeshComp->GetOwner());
	if (!owner) return;

	ACAIController* controller = Cast<ACAIController>(owner->GetController());
	if (!controller)
	{
		UE_LOG(LogTemp, Warning, TEXT("CAnimNotifyHitReactionEnd::AI Controller is null"));
		return;
	}

	if (!controller->GetBlackboardComponent())
	{
		UE_LOG(LogTemp, Warning, TEXT("CAnimNotifyHitReactionEnd::BlackboardComponent is null"));
		return;
	}
	controller->GetBlackboardComponent()->SetValueAsBool(TEXT("bIsTakingHit"), false);
}
