#include "AITasks/CBTTaskNode_Equip.h"
#include "CBTTaskNode_Equip.h"
#include "Enemy/CAIController.h"
#include "Enemy/CEnemyBase_Katana.h"
#include "Components/CWeaponComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTTaskNode_Equip::UCBTTaskNode_Equip()
{
	NodeName = TEXT("Equip Katana");
}

EBTNodeResult::Type UCBTTaskNode_Equip::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACAIController* controller = Cast<ACAIController>(OwnerComp.GetAIOwner());
	if (!controller) return EBTNodeResult::Failed;

	APawn* pawn = controller->GetPawn();
	if (!pawn) return EBTNodeResult::Failed;

	ACEnemyBase_Katana* enemy = Cast<ACEnemyBase_Katana>(pawn);
	if (!enemy) return EBTNodeResult::Failed;

	enemy->GetWeaponComponent();
	if (!enemy->GetWeaponComponent()) return EBTNodeResult::Failed;

	enemy->GetWeaponComponent()->SetKatanaMode();


	return EBTNodeResult::Succeeded;
}
