#pragma once

#include "CoreMinimal.h"
#include "Item/Potions/CPotionBase.h"
#include "CPotionBase_Defense.generated.h"

UCLASS()
class JJW_PROJECT_API ACPotionBase_Defense : public ACPotionBase
{
	GENERATED_BODY()

	virtual void UseItem(class ACPlayer* InOwner) override;

	
};
