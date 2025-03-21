#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Item/CItemStructure.h"
#include "CInventorySlot.generated.h"

UENUM(BlueprintType)
enum EInvenSlotOrder : uint8
{
	Slot_0 = 0,
	Slot_1,
	Slot_2,
	Slot_3,
	Slot_4,
	Slot_5,
	Slot_6,
	Slot_7,
	Slot_8,
	Slot_9
};

UCLASS()
class JJW_PROJECT_API UCInventorySlot : public UObject
{
	GENERATED_BODY()


public:
	FItemStructure* GetItemData() { return ItemData; }
	int32 GetMaxStackCount() { return MaxStackCount; }
	int32 GetCurrentStackCount() { return CurrentStackCount; }

	void IncreaseStackCount() { CurrentStackCount++; }
	void DecreaseStackCount() { CurrentStackCount--; }
	bool IsEmpty() { return ItemData == nullptr; }


	void InitializeSlotData(FItemStructure* InData);
	void ClearSlotData();



private:
	FItemStructure* ItemData;

	int32 MaxStackCount = 0;

	int32 CurrentStackCount = 0;
};
