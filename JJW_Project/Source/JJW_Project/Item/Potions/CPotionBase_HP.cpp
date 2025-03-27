#include "CPotionBase_HP.h"
#include "GameFramework/Character.h"
#include "Player/CPlayer.h"



void ACPotionBase_HP::BeginPlay()
{
	Super::BeginPlay();
}

void ACPotionBase_HP::UseItem(ACPlayer* InOwner)
{
    RemainingDuration = PotionData.Duration;

    //PotionDelegate.BindUObject(this, &ACPotionBase_HP::HealthRestore, InOwner);
	PotionDelegate.BindLambda([this, InOwner]() { HealthRestore(InOwner); });
    
    if (PotionDelegate.IsBound())
    {
        UE_LOG(LogTemp, Warning, TEXT("Delegate successfully bound."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Delegate binding failed."));
        return;
    }

    FTimerManager& TimerManager = InOwner->GetWorldTimerManager();
    TimerManager.SetTimer(TimerHandle, PotionDelegate, 1.f, true);
    
}


void ACPotionBase_HP::HealthRestore(ACPlayer* InOwner)
{
	if (!InOwner) return;
	
	InOwner->IncreamentHealth(PotionData.EffectValue);
	UE_LOG(LogTemp, Warning, TEXT("PlayerHealth: %f"), InOwner->GetCurrentHealth());

	RemainingDuration -= 1.f;

	if (RemainingDuration <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Potion effect ended."));
		FTimerManager& TimerManager = InOwner->GetWorldTimerManager();
		TimerManager.ClearTimer(TimerHandle); // 타이머 정지
	}


}

