#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CInventorySlot.generated.h"

UCLASS()
class JJW_PROJECT_API UCInventorySlot : public UObject
{
	GENERATED_BODY()
	

public:
	void InitializeSlotData();

private:
	struct FItemStructure* ItemData;
};
