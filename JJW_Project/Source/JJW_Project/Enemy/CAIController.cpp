#include "Enemy/CAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"

ACAIController::ACAIController()
{
	Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 800.f;
	SightConfig->LoseSightRadius = 1000.f;
	SightConfig->PeripheralVisionAngleDegrees = 90.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;

	Perception->ConfigureSense(*SightConfig);
	Perception->SetDominantSense(SightConfig->GetSenseImplementation());

}

void ACAIController::OnEnemyPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	if (UpdatedActors.Num() == 0) return;

	TArray<AActor*> actors;
	Perception->GetCurrentlyPerceivedActors(SightConfig->GetSenseImplementation(), actors);

	if (!Blackboard) return;

	if (actors.Num() > 0)
	{
		Blackboard->SetValueAsObject(FName("Target"), actors[0]);
		return;
	}
}

void ACAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (EnemyBT)
	{
		UE_LOG(LogTemp, Warning, TEXT("Behavior Tree is running"));
		RunBehaviorTree(EnemyBT);
	}


}

void ACAIController::BeginPlay()
{
	Super::BeginPlay();

	Perception->OnPerceptionUpdated.AddDynamic(this, &ACAIController::OnEnemyPerceptionUpdated);
}
