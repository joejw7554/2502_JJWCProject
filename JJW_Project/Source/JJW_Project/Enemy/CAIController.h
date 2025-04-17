#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"


UCLASS()
class JJW_PROJECT_API ACAIController : public AAIController
{
	GENERATED_BODY()

public:
	ACAIController();

	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	virtual FGenericTeamId GetGenericTeamId() const override { return FGenericTeamId(TeamID); }

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;


	UFUNCTION()
	void HandleEnemyDead();

protected:
	UFUNCTION()
	void HandleWeaponTypeChanged(bool bIsArmed);

protected:
	UPROPERTY(VisibleAnywhere)
	class UAIPerceptionComponent* Perception;

	UPROPERTY(VisibleAnywhere)
	class UAISenseConfig_Sight* SightConfig;

private:
	uint8 TeamID = 2;

	UPROPERTY()
	class ACEnemyBase* Enemy;
};
