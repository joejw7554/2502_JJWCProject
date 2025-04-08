#pragma once

#include "CoreMinimal.h"
#include "Item/Potions/CPotionBase.h"
#include "CPotionBase_Strength.generated.h"

UCLASS()
class JJW_PROJECT_API ACPotionBase_Strength : public ACPotionBase
{
	GENERATED_BODY()

public:
	virtual void UseItem(class ACPlayer* InOwner) override;

	
};
