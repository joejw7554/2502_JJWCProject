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
	virtual void UseItem(class ACharacter* InOwner) {}

protected:
	UPROPERTY(EditAnywhere, Category = "Potion Property")
	FPotionStructure PotionData;

protected:
	UPROPERTY()
	FTimerHandle TimerHandle;

};
