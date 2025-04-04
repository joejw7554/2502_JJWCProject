#pragma once

#include "CoreMinimal.h"
#include "Item/CItemBase.h"
#include "CPotionStructure.h"
#include "CPotionBase.generated.h"


UCLASS(Abstract)
class JJW_PROJECT_API ACPotionBase : public ACItemBase
{
	GENERATED_BODY()

public:
	virtual void UseItem(class ACPlayer* InOwner) {}

	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Potion Setups")
	FPotionStructure PotionData;

	FTimerHandle TimerHandle;

	float RemainingDuration;
};
