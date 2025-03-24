#include "UI/CUI_Inventory.h"

#include "Components/UniformGridPanel.h"
#include "Components/Button.h"

#include "Player/CPlayerState.h"
#include "Inventory/CInventorySlot.h"
#include "Inventory/CInventoryComponent.h"
#include "CUI_InventorySlot.h"

void UCUI_Inventory::ToggleInventory()
{
	if (IsVisible())
		SetVisibility(ESlateVisibility::Hidden);
	else
		SetVisibility(ESlateVisibility::Visible);
}

void UCUI_Inventory::NativeConstruct()
{
	Super::NativeConstruct();

	SetVisibility(ESlateVisibility::Hidden);

	CloseButton->OnClicked.AddDynamic(this, &UCUI_Inventory::ToggleInventory);

	UWorld* world = GetWorld();
	if (!world)return;

	APlayerController* playerController = Cast<APlayerController>(world->GetFirstPlayerController());
	if (!playerController)return;

	ACPlayerState* playerState = playerController->GetPlayerState<ACPlayerState>();
	if (!playerState)return;

	UCInventoryComponent* inventory = playerState->GetInventoryComponent();
	if (!inventory) return;

	int count = SlotGridPanel->GetChildrenCount();

	for (int i = 0; i < count; i++)
	{
		UCUI_InventorySlot* UI_slot = Cast<UCUI_InventorySlot>(SlotGridPanel->GetChildAt(i));
		if (!UI_slot) UE_LOG(LogTemp, Warning, TEXT("Slot is nullptr"));

		EInvenSlotOrder slotNumberOrder = static_cast<EInvenSlotOrder>(i);
		UI_slot->InitializeSlotWidget(slotNumberOrder, inventory->GetInventorySlot(slotNumberOrder));

		InventorySlots.Add(UI_slot);
	}


}

