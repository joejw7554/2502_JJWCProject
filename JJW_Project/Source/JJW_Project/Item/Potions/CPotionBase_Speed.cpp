#include "Item/Potions/CPotionBase_Speed.h"
#include "Components/CMovementComponent.h"
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
	UCMovementComponent* movementComp= InOwner->GetComponentByClass<UCMovementComponent>();
	if (!movementComp) return;
	
	UE_LOG(LogTemp, Warning, TEXT("%f"), PotionData.EffectValue);
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

	UE_LOG(LogTemp, Warning, TEXT("%f"), PotionData.EffectValue);
	
}


