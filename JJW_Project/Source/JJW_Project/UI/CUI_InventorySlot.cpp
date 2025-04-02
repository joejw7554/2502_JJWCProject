#include "UI/CUI_InventorySlot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Inventory/CInventorySlot.h"
#include "Inventory/CInventoryDragDropOperation.h"

void UCUI_InventorySlot::InitializeSlotWidget(int32 InSlotIndex, UCInventorySlot* InSlot)
{
	if (!InSlot) return;
	SlotIndex = InSlotIndex;
	InventorySlot = InSlot;
	InventorySlot->OnSlotUpdate.AddDynamic(this, &UCUI_InventorySlot::OnSlotUpdate);
	InventorySlot->OnSlotClear.AddDynamic(this, &UCUI_InventorySlot::OnSlotClear);
	
}

void UCUI_InventorySlot::OnSlotUpdate(UCInventorySlot* InSlot)
{
	if (!InSlot) return;

	ItemThumnail->SetBrushFromTexture(InSlot->GetItemData()->Thumbnail);
	ItemThumnail->SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f));
	ItemQuantityText->SetText(FText::FromString(FString::FromInt(InSlot->GetCurrentStackCount())));
	ItemQuantityText->SetVisibility(ESlateVisibility::Visible);
}

void UCUI_InventorySlot::OnSlotClear(UCInventorySlot* InSlot)
{
	ItemThumnail->SetBrushFromTexture(nullptr);
	ItemThumnail->SetColorAndOpacity(FLinearColor(0.f,0.f, 0.f, 1.f));
	ItemQuantityText->SetVisibility(ESlateVisibility::Hidden);
}

void UCUI_InventorySlot::NativeConstruct()
{
	Super::NativeConstruct();

	ItemQuantityText->SetVisibility(ESlateVisibility::Hidden);
}

FReply UCUI_InventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
	{
		if (OnSlotRightClicked.IsBound())
			OnSlotRightClicked.Broadcast(SlotIndex);
	}

	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UCUI_InventorySlot::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{

	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		if (InventorySlot->GetItemData())
		{
			APlayerController* controller = GetWorld()->GetFirstPlayerController();
			if (!controller) return FReply::Unhandled();

			UCInventoryDragDropOperation* DragDropOperation = NewObject<UCInventoryDragDropOperation>(controller);
			if (!DragDropOperation) return FReply::Unhandled();

			DragDropOperation->InitializeDragDropOperation(InventorySlot);
		}
		else
		{
			return FReply::Unhandled();
		}
	}

	return FReply::Handled();
}
