#pragma once

#include "CoreMinimal.h"
#include "Item/Potions/CPotionBase.h"
#include "CPotionBase_HP.generated.h"

UCLASS()
class JJW_PROJECT_API ACPotionBase_HP : public ACPotionBase
{
	GENERATED_BODY()
	
private:
	virtual void UseItem(class ACharacter* InOwner) override;

	void HealthRestore(class ACharacter* InOwner);

private:
	FTimerDelegate TimerDelegate;

};
