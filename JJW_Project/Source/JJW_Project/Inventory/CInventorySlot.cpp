#include "Inventory/CInventorySlot.h"

void UCInventorySlot::SetItemInSlot(FItemStructure* InData, int32 Count)
{
	ItemData = InData;
	MaxStackCount = InData->MaxStack;
	CurrentStackCount = Count;
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
}
