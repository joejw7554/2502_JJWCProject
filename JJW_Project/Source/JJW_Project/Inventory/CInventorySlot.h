#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Item/CItemStructure.h"
#include "CInventorySlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSlotUpdate);

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
	int32 GetSlotIndex() { return SlotIndex; }

	void IncreaseStackCount() { CurrentStackCount++; }
	void DecreaseStackCount() { CurrentStackCount--; }
	bool IsEmpty() { return ItemData == nullptr; }

	void SetItemInSlot(FItemStructure* InData ,int32 Count=1);
	void InitializeSlot(int32 InSlotIndex);
	void ClearSlotData();

protected:
	//void RefreshSlotData();

private:


public:
	FSlotUpdate OnSlotUpdate;

private:
	FItemStructure* ItemData;

	int32 MaxStackCount = 0;

	int32 CurrentStackCount = 0;

	int32 SlotIndex = 0;
};
