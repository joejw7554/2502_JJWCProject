#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CBTService_CheckEnemy.generated.h"

UCLASS()
class JJW_PROJECT_API UCBTService_CheckEnemy : public UBTService
{
	GENERATED_BODY()
	
public:
	UCBTService_CheckEnemy();

private:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
