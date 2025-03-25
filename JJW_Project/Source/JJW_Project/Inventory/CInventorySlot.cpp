#include "Inventory/CInventorySlot.h"

void UCInventorySlot::SetStackCount(int32 InCount)
{
	if (InCount <= 0)
	{
		ClearSlotData();
		return;
	}

	if (InCount != CurrentStackCount)
	{
		CurrentStackCount = InCount;
		if (OnSlotUpdate.IsBound())
			OnSlotUpdate.Broadcast(this);
	}
}

void UCInventorySlot::SetItemInSlot(FItemStructure* InData, int32 Count)
{
	ItemData = InData;
	MaxStackCount = InData->MaxStack;
	CurrentStackCount = Count;
	if (OnSlotUpdate.IsBound())
		OnSlotUpdate.Broadcast(this);
}

void UCInventorySlot::InitializeSlot(int32 InSlotIndex)
{
	SlotIndex = InSlotIndex;
}

void UCInventorySlot::ClearSlotData()
{
	ItemData = nullptr;
	CurrentStackCount = 0;
	MaxStackCount = 0;

	if (OnSlotClear.IsBound())
	OnSlotClear.Broadcast(this);
}
