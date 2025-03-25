#include "Inventory/CInventoryComponent.h"

#include "CInventorySlot.h"
#include "Framework/CHUD.h"
#include "UI/CUI_Inventory.h"
#include "UI/CUI_InventorySlot.h"

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
			//여기서 Slot 이랑 Slot UI 바인딩 타이밍이 될려나? 그래서 BeginPlay에서 바인딩을할꺼임

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
					if (OnSlotUpdate.IsBound())
						OnSlotUpdate.Broadcast(slot.Value);
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
			if (OnSlotUpdate.IsBound())
				OnSlotUpdate.Broadcast(slot.Value);
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

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	if (!controller) return;

	ACHUD* CHUD = controller->GetHUD<ACHUD>();
	if (!CHUD) return;

	UCUI_Inventory* InventoryWidget = CHUD->GetMainHUD()->GetInventoryWidget();
	if (!InventoryWidget) return;

	TArray<UCUI_InventorySlot*> UI_Slots = InventoryWidget->GetInventorySlots();
	if (UI_Slots.IsEmpty()) return;


	UCInventorySlot* slot;
	UCUI_InventorySlot* UI_Slot;

	for (int i = 0; i < InventorySlots.Num(); i++)
	{
		if (InventorySlots[static_cast<EInvenSlotOrder>(i)] == nullptr) continue;

		slot = InventorySlots[static_cast<EInvenSlotOrder>(i)];
		UI_Slot = UI_Slots[i];

		UI_Slot->AssignInventorySlot(slot);
		UE_LOG(LogTemp, Warning, TEXT("UCInventoryComponent::BeginPlay - Slot %d is assigned"), i);
		OnSlotUpdate.AddDynamic(UI_Slot, &UCUI_InventorySlot::OnSlotUpdate);
	}


}

UCInventorySlot* UCInventoryComponent::FindEmptySlot()
{
	if (CheckInventoryFull()) return nullptr;

	for (const TPair<TEnumAsByte<EInvenSlotOrder>, UCInventorySlot*>& slot : InventorySlots)
	{
		if (slot.Value->IsEmpty())
			return slot.Value;
	}

	return nullptr;
}
