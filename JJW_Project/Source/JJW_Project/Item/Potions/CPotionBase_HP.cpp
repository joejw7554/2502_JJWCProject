#include "CPotionBase_HP.h"
#include "GameFramework/Character.h"
#include "Player/CPlayer.h"

void ACPotionBase_HP::UseItem(ACPlayer* InOwner)
{
	RemainingDuration = PotionData.Duration; // 남은 지속 시간 초기화
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUObject(this, &ACPotionBase_HP::HealthRestore, InOwner);

	
	FTimerManager& TimerManager =InOwner->GetWorldTimerManager();
	TimerManager.ClearTimer(TimerHandle);
	TimerManager.SetTimer(TimerHandle, TimerDelegate, PotionData.Duration, false);
}

void ACPotionBase_HP::HealthRestore(ACPlayer* InOwner)
{
	UE_LOG(LogTemp, Warning, TEXT("Potion effect started."));

	if (!InOwner) UE_LOG(LogTemp, Warning, TEXT("Owner is nullptr"));
	if (!InOwner) return;

	
	
	ACPlayer* player = Cast<ACPlayer>(InOwner);
	if (!player) 
		UE_LOG(LogTemp, Warning, TEXT("Player is nullptr"));

	if (!player) return;

	player->IncreamentHealth(PotionData.EffectValue);
	UE_LOG(LogTemp, Warning, TEXT("PlayerHealth: %f"), player->GetCurrentHealth());

	RemainingDuration -= 1.f;

	if (RemainingDuration <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Potion effect ended."));
		FTimerManager& TimerManager = InOwner->GetWorldTimerManager();
		TimerManager.ClearTimer(TimerHandle); // 타이머 정지
	}


}
