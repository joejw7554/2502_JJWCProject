#include "Stats/CStatComponent.h"

UCStatComponent::UCStatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCStatComponent::IncrementStat(FName InStat)
{
	if (AvailableStatPoint <= 0) return;

	if (InStat == "Strength")
	{
		StatStructure.Strength += 1.f;
		AvailableStatPoint--;
	}
	else if (InStat == "Defense")
	{
		StatStructure.Defense += 1.f;
		AvailableStatPoint--;
	}

	if (OnStatPointUpdate.IsBound())
		OnStatPointUpdate.Broadcast(AvailableStatPoint);
}

void UCStatComponent::DecrementStat(FName InStat)
{
	if (AvailableStatPoint <= 0) return;

	if (InStat == "Strength")
	{
		if (StatStructure.Strength <= 1.f) return; // 최소 스탯 1로 설정
		StatStructure.Strength -= 1.f;
		AvailableStatPoint++;
	}
	else if (InStat == "Defense")
	{
		if (StatStructure.Defense <= 1.f) return; // 최소 스탯 1로 설정
		StatStructure.Defense -= 1.f;
		AvailableStatPoint++;
	}

	if (OnStatPointUpdate.IsBound())
		OnStatPointUpdate.Broadcast(AvailableStatPoint);
}

void UCStatComponent::SetAvailableStatPoint(uint8 InStatPoint)
{
	AvailableStatPoint += InStatPoint;

	if (OnStatPointUpdate.IsBound())
		OnStatPointUpdate.Broadcast(AvailableStatPoint);
}


void UCStatComponent::BeginPlay()
{
	Super::BeginPlay();

	
	OnStatPointUpdate.Broadcast(AvailableStatPoint);
	OnEXPUpdate.Broadcast(GetCurrentEXPPercent());
}

void UCStatComponent::AddPlayerEXP(float InEXP)
{
	CurrentEXP += InEXP;

	// 레벨업이 가능한 만큼 반복
	while (CurrentEXP >= MaxEXP)
	{
		// 레벨업 처리
		CurrentLevel++;
		SetAvailableStatPoint(LevelUpProvidingStatPoint);
		ExtendMaxEXP();
	}

	// EXP 업데이트 이벤트 호출
	if (OnEXPUpdate.IsBound())
		OnEXPUpdate.Broadcast(GetCurrentEXPPercent());
}

void UCStatComponent::ExtendMaxEXP()
{
	CurrentEXP -= MaxEXP; // 현재 경험치에서 MaxEXP를 빼서 남은 경험치 저장
	MaxEXP *= MaxEXPIncrement; // MaxEXP를 증가
}

void UCStatComponent::ApplyBuff(FName StatName, float BuffAmount, float Duration)
{
	TemporaryStatBonuses.FindOrAdd(StatName) += BuffAmount;

	FTimerHandle* timer = BuffTimers.Find(StatName);
	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	if (timer && timerManager.IsTimerActive(*timer))
	{
		timerManager.ClearTimer(*timer);
	}


	FTimerHandle newTimer;
	BuffTimers.Add(StatName, newTimer);
	timerManager.SetTimer(newTimer, [this, StatName]()
		{
			RemoveBuff(StatName);
		}, Duration, false);
}

void UCStatComponent::RemoveBuff(FName StatName)
{
	FTimerHandle* timer = BuffTimers.Find(StatName);
	FTimerManager& timerManager = GetWorld()->GetTimerManager();

	if (timer)
	{
		timerManager.ClearTimer(*timer);
		BuffTimers.Remove(StatName);
		TemporaryStatBonuses.Remove(StatName);
	}
}

float UCStatComponent::GetStatValue(FName StatName) const
{
	float BaseValue = 0.f;

	if (StatName == "Strength")
	{
		BaseValue = StatStructure.Strength;
	}
	else if (StatName == "Defense")
	{
		BaseValue = StatStructure.Defense;
	}

	float BonusValue =0.f;

	if (TemporaryStatBonuses.Contains(StatName))
	{
		BonusValue = TemporaryStatBonuses[StatName];
	}

	return BaseValue + BonusValue; // 기본 값 + 임시 버프 값 반환
}
