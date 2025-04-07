#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatStructure.h"
#include "CStatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatPointUpdate, uint8, InValue);

UCLASS()
class JJW_PROJECT_API UCStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	FStatPointUpdate OnStatPointUpdate;

public:	
	UCStatComponent();
	
	UFUNCTION()
	void IncrementStat(FName InStat);

	UFUNCTION()
	void DecrementStat(FName InStat);

	void SetAvailableStatPoint(uint8 InStatPoint);

	void AddPlayerEXP(float InEXP);

protected:
	virtual void BeginPlay() override;

	void ExtendMaxEXP();
public:	
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE FStatsStructure const GetStatStructure() { return StatStructure; }
		
private:
	UPROPERTY(EditDefaultsOnly)
	FStatsStructure StatStructure;

	UPROPERTY(VisibleAnywhere)
	uint8 CurrentLevel = 1;

	UPROPERTY()
	uint8 AvailableStatPoint = 0;

	UPROPERTY(EditAnywhere)
	uint8 LevelUpProvidingStatPoint = 5;

	UPROPERTY(EditAnywhere)
	float CurrentEXP = 0.f;

	UPROPERTY(EditAnywhere)
	float MaxEXP = 100.f;

	UPROPERTY(EditAnywhere)
	float MaxEXPIncrement = 1.2f;
};
