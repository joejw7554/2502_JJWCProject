#include "UI/CUI_InventorySlot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"




void UCUI_InventorySlot::InitializeSlotWidget(UCInventorySlot* InSlot)
{
	if (!InSlot) return;

	InventorySlot = InSlot;

}

void UCUI_InventorySlot::NativePreConstruct()
{
	Super::NativePreConstruct();

}

void UCUI_InventorySlot::NativeConstruct()
{
	Super::NativeConstruct();

}
