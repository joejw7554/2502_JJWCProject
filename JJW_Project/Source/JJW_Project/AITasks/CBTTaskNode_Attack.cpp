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
	if (!controller)return EBTNodeResult::Failed;
	
	APawn* pawn = controller->GetPawn();
	if (!pawn)return EBTNodeResult::Failed;

	ACEnemyBase_Katana* enemy = Cast<ACEnemyBase_Katana>(pawn);
	if (!enemy)return EBTNodeResult::Failed;

	bool bIsPlayingMontage = enemy->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying();
	if (bIsPlayingMontage) return EBTNodeResult::Failed;

	UCMovementComponent_Enemy* movementComponent = enemy->GetMovementComponent();
	if (!movementComponent)return EBTNodeResult::Failed;

	AActor* target= Cast<AActor>(controller->GetBlackboardComponent()->GetValueAsObject(TEXT("Target")));
	if (!target)return EBTNodeResult::Failed;
	
	FVector targetLocation = target->GetActorLocation();
	FVector currentLocation = pawn->GetActorLocation();
	
	FRotator targetRotation = (targetLocation - currentLocation).Rotation();
	targetRotation.Pitch = 0.f;
	targetRotation.Roll = 0.f;
	movementComponent->SetTargetRotation(targetRotation);

	UCWeaponComponent* weaponComponent = enemy->GetWeaponComponent();
	if (!weaponComponent) return EBTNodeResult::Failed;
	int skillKey= FMath::RandRange(0,4);
	ESkillKey skill = static_cast<ESkillKey>(skillKey);
	weaponComponent->DoSkill(skill);

	

	return EBTNodeResult::Succeeded;
}

