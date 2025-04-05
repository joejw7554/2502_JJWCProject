#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatStructure.h"
#include "CStatComponent.generated.h"


UCLASS()
class JJW_PROJECT_API UCStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStatComponent();
	
	void IncrementStat(FName InStat);
	void DecrementStat(FName InStat);

protected:
	virtual void BeginPlay() override;

public:	
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FStatsStructure GetStatStructure() const { return StatStructure; }
		
private:
	UPROPERTY()
	FStatsStructure StatStructure;
};
