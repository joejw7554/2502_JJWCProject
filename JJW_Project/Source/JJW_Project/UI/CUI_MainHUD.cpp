#include "UI/CUI_MainHUD.h"
#include "UI/CUI_Inventory.h"

void UCUI_MainHUD::ToggleInventoryUI(bool bShow)
{
	if (!InventoryWidget) return;

	if(bShow)
	{
		InventoryWidget->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	
}
