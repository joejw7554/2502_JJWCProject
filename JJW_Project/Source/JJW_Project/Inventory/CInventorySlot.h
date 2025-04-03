#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Item/CItemStructure.h"
#include "CInventorySlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotUpdate, UCInventorySlot*, InSlot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotClear, UCInventorySlot*, InSlot);

UCLASS()
class JJW_PROJECT_API UCInventorySlot : public UObject
{
	GENERATED_BODY()

public:
	FSlotUpdate OnSlotUpdate;
	FSlotClear OnSlotClear;

public:
	FItemStructure* GetItemData() { return ItemData; }
	class ACItemBase* GetItemInstance() { return ItemData ? ItemData->ItemInstance : nullptr; }
	int32 GetMaxStackCount() { return MaxStackCount; }
	int32 GetCurrentStackCount() { return CurrentStackCount; }

	void IncreaseStackCount() { SetStackCount(CurrentStackCount + 1); }
	void DecreaseStackCount() { SetStackCount(CurrentStackCount - 1); }
	void AddStackCount(int32 InCount) { SetStackCount(InCount+ CurrentStackCount); }
	void SetItemInSlot(FItemStructure* InData ,int32 Count=1);
	bool IsEmpty() { return ItemData == nullptr; }

	void ClearSlotData();

protected:
	void SetStackCount(int32 InCount);

private:
	FItemStructure* ItemData;

	UPROPERTY()
	int32 MaxStackCount = 0;

	UPROPERTY()
	int32 CurrentStackCount = 0;
};
