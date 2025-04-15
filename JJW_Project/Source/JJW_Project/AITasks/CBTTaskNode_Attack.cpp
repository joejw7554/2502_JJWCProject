#include "AITasks/CBTTaskNode_Attack.h"
#include "CBTTaskNode_Attack.h"
#include "Enemy/CAIController.h"
#include "Enemy/CEnemyBase_Katana.h"
#include "Components/CWeaponComponent.h"
#include "Weapons/CSkillStructure.h"
#include "Enemy/CMovementComponent_Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTTaskNode_Attack::UCBTTaskNode_Attack()
{
	NodeName = TEXT("Attack");
}

EBTNodeResult::Type UCBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACAIController* controller = Cast<ACAIController>(OwnerComp.GetAIOwner());

	if (!controller)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller is null"));
		return EBTNodeResult::Failed;
	}

	APawn* pawn = controller->GetPawn();
	if (!pawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn is null"));
		return EBTNodeResult::Failed;
	}

	ACEnemyBase_Katana* enemy = Cast<ACEnemyBase_Katana>(pawn);
	if (!enemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy is null"));
		return EBTNodeResult::Failed;
	}

	UCMovementComponent_Enemy* movementComponent = enemy->GetMovementComponent();
	if (!movementComponent)return EBTNodeResult::Failed;

	AActor* target= Cast<AActor>(controller->GetBlackboardComponent()->GetValueAsObject(TEXT("Target")));
	if (!target)return EBTNodeResult::Failed;
	
	FVector targetLocation = target->GetActorLocation();
	FVector location = pawn->GetActorLocation();
	/////COntinue from here


	UCWeaponComponent* weaponComponent = enemy->GetWeaponComponent();
	if (!weaponComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("WeaponComponent is null"));
		return EBTNodeResult::Failed;
	}
	int skillKey= FMath::RandRange(0,4);

	ESkillKey skill = static_cast<ESkillKey>(skillKey);
	
	weaponComponent->DoSkill(skill);
	

	return EBTNodeResult::Succeeded;
}

