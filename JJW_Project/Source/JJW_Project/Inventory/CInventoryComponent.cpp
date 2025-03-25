#include "Inventory/CInventoryComponent.h"
#include "CInventorySlot.h"

UCInventoryComponent::UCInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	InventorySlots.Reserve(InventoryMaxSize);
	InventorySlots.Empty();

	for (int i = 0; i < InventoryMaxSize; i++)
	{
		UCInventorySlot* slot = CreateDefaultSubobject<UCInventorySlot>(FName(*FString::Printf(TEXT("Slot_%d"), i)));
		if (slot)
		{
			slot->ClearSlotData();
			InventorySlots.Add(static_cast<EInvenSlotOrder>(i), slot);
			slot->InitializeSlot(i);
		}
	}
}

bool UCInventoryComponent::AddItemToInventory(FItemStructure* InItemData)
{
	if (!InItemData)
	{
		UE_LOG(LogTemp, Warning, TEXT("UCInventoryComponent::AddItemToInventory - InItemData is nullptr"));
		return false;
	}

	FItemStructure* current;

	for (const TPair<TEnumAsByte<EInvenSlotOrder>, UCInventorySlot*>& slot : InventorySlots)
	{
		//TMap에 같은 아이템이 있는지 없는지 확인한다

		//빈 Empty Slot을 먼저 찾는다?
		current = slot.Value->GetItemData();

		//일단 같은 아이템이 있는지 없는지부터 순회
		if (!slot.Value->IsEmpty())
		{
			if (current->ItemID == InItemData->ItemID)
			{
				//같은 아이템이 있다면 그 해당 셀의 현재갯수를 업데이트한다
				if (slot.Value->GetCurrentStackCount() < current->MaxStack)
				{
					slot.Value->IncreaseStackCount();
					return true;
				}
			}
		}
	}
	
	if (CheckInventoryFull()) return false;

	//여기까지 왔다면 같은 아이템이 없다는뜻으로 빈슬롯을 찾아 아이템 추가
	for (const TPair<TEnumAsByte<EInvenSlotOrder>, UCInventorySlot*>& slot : InventorySlots)
	{
		if (slot.Value->IsEmpty())
		{
			slot.Value->SetItemInSlot(InItemData);
			return true;
		}
	}

	return false;
}

bool UCInventoryComponent::CheckInventoryFull()
{
	for (TPair<TEnumAsByte<EInvenSlotOrder>, UCInventorySlot*>& slot : InventorySlots)
	{
		if (slot.Value->IsEmpty())
			return false;
	}

	return true;
}

void UCInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

UCInventorySlot* UCInventoryComponent::FindEmptySlot()
{
	if (CheckInventoryFull()) return nullptr;

	for (const TPair<TEnumAsByte<EInvenSlotOrder>, UCInventorySlot*>& slot : InventorySlots)
	{
		if(slot.Value->IsEmpty())
			return slot.Value;
	}

	return nullptr;
}
