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
		}
	}
}

bool UCInventoryComponent::AddItemToInventory(FItemStructure* InItemData)
{
	bool bSuccess = false;
	if (!InItemData) return false;

	FItemStructure* current;
	UCInventorySlot* emptySlot = nullptr;

	for (const TPair<TEnumAsByte<EInvenSlotOrder>, UCInventorySlot*>& slot : InventorySlots)
	{
		//TMap에 같은 아이템이 있는지 없는지 확인한다
		current = slot.Value->GetItemData();
		if (current->ItemID == InItemData->ItemID)
		{
			//같은 아이템이 있다면 그 해당 셀의 현재갯수를 업데이트한다
			if (slot.Value->GetCurrentStackCount() < current->MaxStack)
			{
				slot.Value->IncreaseStackCount();
				bSuccess = true;
				break;
			}
			else
			{
				//만약 같은 아이템이 있는 셀의 최대갯수를 넘어가면 다음 빈셀로 찾는다 그리고 데이터를 초기화한다 =빈 공간을 찾아야하는 경우의수 
				emptySlot = FindEmptySlot();
				if (emptySlot)
				{
					emptySlot->InitializeSlotData(InItemData);
					bSuccess = true;
					break;
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Inventory is Full"));
					break;
				}
			}
		}
		else
		{
			//같은 아이템이 없다면 빈셀을 찾아서 데이터를 넣는다 = 빈 공간을 찾아야하는 경우의 수 
			emptySlot = FindEmptySlot();
			if (emptySlot)
			{
				emptySlot->InitializeSlotData(InItemData);
				bSuccess = true;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Inventory is Full"));
				break;
			}
		}
	}
	
	return bSuccess;
}

bool UCInventoryComponent::CheckInventoryFull()
{
	return InventorySlots.Num() >= InventoryMaxSize;
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
