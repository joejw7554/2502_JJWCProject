#include "AITasks/CBTService_CheckEnemy.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTService_CheckEnemy::UCBTService_CheckEnemy()
{
	NodeName = TEXT("Check Enemy");
}

void UCBTService_CheckEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* controller = OwnerComp.GetAIOwner();
	if (!controller) return;

	UBlackboardComponent* blackboardComp = controller->GetBlackboardComponent();
	if (!blackboardComp)return;

	AActor* target = Cast<AActor>(blackboardComp->GetValueAsObject("Target"));
	if (!target) return;

	const IGenericTeamAgentInterface* targetTeam = Cast<IGenericTeamAgentInterface>(target);
	if (!targetTeam) return;

	FGenericTeamId AI_teamID = controller->GetGenericTeamId();
	FGenericTeamId target_teamID = targetTeam->GetGenericTeamId();

	if (AI_teamID != target_teamID)
	{
		blackboardComp->SetValueAsBool("bIsEnemy", true);
	}
	else
	{
		blackboardComp->SetValueAsBool("bIsEnemy", false);
	}
	


	
}
