#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CBTService_CheckDistance.generated.h"

UCLASS()
class JJW_PROJECT_API UCBTService_CheckDistance : public UBTService
{
	GENERATED_BODY()
	
public:
	UCBTService_CheckDistance();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
