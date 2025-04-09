#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"

UCLASS()
class JJW_PROJECT_API ACAIController : public AAIController
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* EnemyBT;
};
