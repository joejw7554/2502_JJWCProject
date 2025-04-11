#include "Enemy/CAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CEnemyBase.h"
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
	if (!UpdatedActors.Num()) return; // Ignore if no actors updated

	// Get the currently perceived actors (ensuring only those in sight)
	TArray<AActor*> PerceivedActors;
	Perception->GetCurrentlyPerceivedActors(TSubclassOf<UAISense_Sight>(), PerceivedActors);

	if (!PerceivedActors.IsEmpty() && Blackboard)
	{
		// Set the first perceived actor as the target in the Blackboard
		Blackboard->SetValueAsObject(FName("Target"), PerceivedActors[0]);
		UE_LOG(LogTemp, Warning, TEXT("Perceived Actor: %s"), *PerceivedActors[0]->GetName());
	}
	else if (Blackboard)
	{
		// Clear the target if no actors are perceived
		Blackboard->ClearValue(FName("Target"));
		UE_LOG(LogTemp, Warning, TEXT("No actors perceived, clearing Target."));
	}
}

void ACAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);


	UE_LOG(LogTemp, Warning, TEXT("Behavior Tree is running"));
	Enemy = Cast<ACEnemyBase>(GetOwner());

	if (!Enemy)return;
	if (!Enemy->GetBehaviorTree()) return;

	RunBehaviorTree(Enemy->GetBehaviorTree());
}

void ACAIController::BeginPlay()
{
	Super::BeginPlay();

	Perception->OnPerceptionUpdated.AddDynamic(this, &ACAIController::OnEnemyPerceptionUpdated);
}
