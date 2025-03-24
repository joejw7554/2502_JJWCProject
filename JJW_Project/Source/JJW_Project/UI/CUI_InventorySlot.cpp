#include "UI/CUI_InventorySlot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"




void UCUI_InventorySlot::InitializeSlotWidget(int32 InSlotIndex, UCInventorySlot* InSlot)
{
	if (!InSlot) return;
	SlotIndex = InSlotIndex;
	InventorySlot = InSlot;
}

void UCUI_InventorySlot::NativePreConstruct()
{
	Super::NativePreConstruct();

}

void UCUI_InventorySlot::NativeConstruct()
{
	Super::NativeConstruct();

	SlotButton->OnClicked.AddDynamic(this, &UCUI_InventorySlot::LeftMouseButtonClicked);
}

FReply UCUI_InventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
//Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		RightMouseButtonClicked();
	}


	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UCUI_InventorySlot::LeftMouseButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("LeftMouse"));
}

void UCUI_InventorySlot::RightMouseButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("RightMouse"));

}
