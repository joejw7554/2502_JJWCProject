#include "Item/Potions/CPotionBase_Speed.h"
#include "Components/CMovementComponent.h"
#include "Player/CPlayer.h"

void ACPotionBase_Speed::UseItem(ACPlayer* InOwner)
{
	RemainingDuration = PotionData.Duration;

	FTimerManager& timerManager = InOwner->GetWorldTimerManager();
	FTimerDelegate PotionDelegate;
	PotionDelegate.BindLambda([this, InOwner]() { IncreaseSpeed(InOwner); });
}

void ACPotionBase_Speed::IncreaseSpeed(ACPlayer* InOwner)
{
	if (!InOwner) return;

	UCMovementComponent* movementComp= InOwner->GetComponentByClass<UCMovementComponent>();
	if (!movementComp) return;
	RemainingDuration -= 1.f;
	float speed = movementComp->GetMaxWalkSpeed();
	movementComp->IncreamentSpeed(PotionData.EffectValue);

	if (RemainingDuration <= 0.f)
	{
		movementComp->DecreamentSpeed(PotionData.EffectValue);
		FTimerManager& TimerManager = InOwner->GetWorldTimerManager();
		TimerManager.ClearTimer(TimerHandle); // 타이머 정지
	}
}


