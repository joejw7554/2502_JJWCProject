#pragma once

#include "CoreMinimal.h"
#include "Item/CItemBase.h"
#include "CItemBase_Potion_HP.generated.h"

UCLASS()
class JJW_PROJECT_API ACItemBase_Potion_HP : public ACItemBase
{
	GENERATED_BODY()
	
protected:
	virtual void UseItem() override;
};
