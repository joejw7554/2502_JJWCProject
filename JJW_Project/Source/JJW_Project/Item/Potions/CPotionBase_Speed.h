#pragma once

#include "CoreMinimal.h"
#include "Item/Potions/CPotionBase.h"
#include "CPotionBase_Speed.generated.h"

UCLASS()
class JJW_PROJECT_API ACPotionBase_Speed : public ACPotionBase
{
	GENERATED_BODY()

protected:
	virtual void UseItem(class ACPlayer* InOwner) override;

	void IncreaseSpeed(class ACPlayer* InOwner);
	
	float BaseWalkSpeed;
};
