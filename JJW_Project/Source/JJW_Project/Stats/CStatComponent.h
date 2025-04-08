#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatStructure.h"
#include "CStatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatPointUpdate, uint8, InValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEXPUpdate, float, InPercent);

UCLASS()
class JJW_PROJECT_API UCStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	FStatPointUpdate OnStatPointUpdate;
	FEXPUpdate OnEXPUpdate;

public:
	UCStatComponent();

	UFUNCTION()
	void IncrementStat(FName InStat);

	UFUNCTION()
	void DecrementStat(FName InStat);

	void SetAvailableStatPoint(uint8 InStatPoint);

	void AddPlayerEXP(float InEXP);

	float GetCurrentEXPPercent() { return CurrentEXP / MaxEXP; }

	//For UI
	FORCEINLINE FStatsStructure const& GetStatStructure() { return StatStructure; }

	//For Combat

protected:
	virtual void BeginPlay() override;

	void ExtendMaxEXP();

private:
	UPROPERTY(EditDefaultsOnly)
	FStatsStructure StatStructure;

	TMap<FName, FTimerHandle> BuffTimers; // 스탯 이름과 타이머를 매핑
	TMap<FName, float> TemporaryStatBonuses; // 스탯 이름과 보너스를 매핑

public:
	void ApplyBuff(FName StatName, float BuffAmount, float Duration);
	void RemoveBuff(FName StatName);
	float GetStatValue(FName StatName) const;


private:
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
