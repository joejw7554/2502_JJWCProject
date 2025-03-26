#include "CPotionBase_HP.h"
#include "GameFramework/Character.h"
#include "Player/CPlayer.h"

void ACPotionBase_HP::UseItem(ACharacter* InOwner)
{
	FTimerManager& TimerManager = InOwner->GetWorldTimerManager();
	TimerDelegate.BindUObject(this, &ACPotionBase_HP::HealthRestore, InOwner);


	TimerManager.SetTimer(TimerHandle,TimerDelegate, PotionData.Duration, false);

}

void ACPotionBase_HP::HealthRestore(ACharacter* InOwner)
{
	if (!InOwner) return;


	ACPlayer* Player = Cast<ACPlayer>(InOwner);
	if (!Player) return;

	Player->IncreamentHealth(PotionData.EffectValue);

	UE_LOG(LogTemp, Warning, TEXT("PlayerHealth: %f"), Player->GetCurrentHealth());
}
