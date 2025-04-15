#include "AITasks/CBTService_CheckDistance.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "Enemy/CAIController.h"
UCBTService_CheckDistance::UCBTService_CheckDistance()
{
	NodeName = TEXT("Check Distance");
}

void UCBTService_CheckDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* controller = OwnerComp.GetAIOwner();
	if (!controller) return;

	UBlackboardComponent* blackboardComp = controller->GetBlackboardComponent();
	if (!blackboardComp)return;
	AActor* target = Cast<AActor>(blackboardComp->GetValueAsObject("Target"));
	if (!target) return;

	APawn* pawn = controller->GetPawn();
	if (!pawn) return;

	float toleranceRange = blackboardComp->GetValueAsFloat("ToleranceRange");
	float distance = FVector::Distance(pawn->GetActorLocation(), target->GetActorLocation());

	if (distance <= toleranceRange)
	{
		blackboardComp->SetValueAsBool("bIsInRange", true);
	}
	else
	{
		blackboardComp->SetValueAsBool("bIsInRange", false);
	}

}
