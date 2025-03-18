#pragma once

#include "CoreMinimal.h"
#include "Item/CItemBase.h"
#include "CItemBase_Potion_HP.generated.h"

UCLASS()
class JJW_PROJECT_API ACItemBase_Potion_HP : public ACItemBase
{
	GENERATED_BODY()
	
public:
	ACItemBase_Potion_HP();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

protected:
	virtual void UseItem() override;
};
