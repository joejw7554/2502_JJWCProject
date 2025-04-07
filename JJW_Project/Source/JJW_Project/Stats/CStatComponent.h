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
	
	UFUNCTION()
	void IncrementStat(FName InStat);

	UFUNCTION()
	void DecrementStat(FName InStat);

protected:
	virtual void BeginPlay() override;

public:	
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE FStatsStructure const GetStatStructure() { return StatStructure; }
		
private:
	UPROPERTY(EditDefaultsOnly)
	FStatsStructure StatStructure;
};
