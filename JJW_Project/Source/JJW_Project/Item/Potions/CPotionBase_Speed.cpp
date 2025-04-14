#include "Item/Potions/CPotionBase_Speed.h"
#include "Player/CMovementComponent_Player.h"
#include "Player/CPlayer.h"

void ACPotionBase_Speed::UseItem(ACPlayer* InOwner)
{
	RemainingDuration = PotionData.Duration;

	FTimerDelegate PotionDelegate;
	PotionDelegate.BindLambda([this, InOwner]() { IncreaseSpeed(InOwner); });

	if (PotionDelegate.IsBound())
	{
		FTimerManager& timerManager = InOwner->GetWorldTimerManager();
		timerManager.SetTimer(TimerHandle, PotionDelegate, 1.f, true);
	}
	
}

void ACPotionBase_Speed::IncreaseSpeed(ACPlayer* InOwner)
{
	if (!InOwner) return;
	UCMovementComponent_Player* movementComp= InOwner->GetComponentByClass<UCMovementComponent_Player>();
	if (!movementComp) return;
	
	movementComp->SetBueffedWalkSpeed(PotionData.EffectValue);


	RemainingDuration -= 1.f;
	if (RemainingDuration <= 0.f)
	{
		movementComp->SetWalkMode();
		FTimerManager& TimerManager = InOwner->GetWorldTimerManager();
		TimerManager.ClearTimer(TimerHandle); // 타이머 정지
	}
}

void ACPotionBase_Speed::BeginPlay()
{
	Super::BeginPlay();

	
}


