#include "Inventory/CInventorySlot.h"


void UCInventorySlot::InitializeSlotData(FItemStructure* InData)
{
	ItemData = InData;
	MaxStackCount = InData->MaxStack;
	CurrentStackCount = 1;
}

void UCInventorySlot::ClearSlotData()
{
	ItemData = nullptr;
	CurrentStackCount = 0;
	MaxStackCount = 0;
}
