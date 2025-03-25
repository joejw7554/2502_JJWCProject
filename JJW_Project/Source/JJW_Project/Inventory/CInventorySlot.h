#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Item/CItemStructure.h"
#include "CInventorySlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotUpdate, UCInventorySlot*, InSlot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotClear, UCInventorySlot*, InSlot);



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
	FSlotUpdate OnSlotUpdate;
	FSlotClear OnSlotClear;

public:
	FItemStructure* GetItemData() { return ItemData; }
	int32 GetMaxStackCount() { return MaxStackCount; }
	int32 GetCurrentStackCount() { return CurrentStackCount; }
	int32 GetSlotIndex() { return SlotIndex; }

	void IncreaseStackCount() { SetStackCount(CurrentStackCount + 1); }
	void DecreaseStackCount() { SetStackCount(CurrentStackCount - 1); }
	void SetItemInSlot(FItemStructure* InData ,int32 Count=1);
	bool IsEmpty() { return ItemData == nullptr; }

	void InitializeSlot(int32 InSlotIndex);
	void ClearSlotData();

protected:
	void SetStackCount(int32 InCount);

private:
	FItemStructure* ItemData;

	UPROPERTY()
	int32 MaxStackCount = 0;

	UPROPERTY()
	int32 CurrentStackCount = 0;

	UPROPERTY()
	int32 SlotIndex = 0;
};
