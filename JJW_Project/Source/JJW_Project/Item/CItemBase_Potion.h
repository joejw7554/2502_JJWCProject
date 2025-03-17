#pragma once

#include "CoreMinimal.h"
#include "Item/CItemBase.h"
#include "CItemBase_Potion.generated.h"

UCLASS()
class JJW_PROJECT_API ACItemBase_Potion : public ACItemBase
{
	GENERATED_BODY()

public:
	ACItemBase_Potion();

protected:
	virtual void UseItem() override;
	
};
