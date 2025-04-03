#include "UI/CUI_InventorySlot.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

#include "Inventory/CInventorySlot.h"
#include "UI/CUI_SlotDragPreview.h"
#include "Inventory/CInventoryDragDropOperation.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Item/CItemStructure.h"
#include "Player/CPlayerState.h"
#include "Inventory/CInventoryComponent.h"

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

	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		if (InventorySlot->GetItemData())
		{
			FEventReply reply;
			reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton);
			return reply.NativeReply;
		}
	}

	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UCUI_InventorySlot::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	if (!DragDropClass) return;
	UCInventoryDragDropOperation* dragDropOperation = NewObject<UCInventoryDragDropOperation>(GetWorld(), DragDropClass);
	OutOperation = dragDropOperation;

	if (!DragPreviewClass) return;
	UCUI_SlotDragPreview* PreviewWidget = CreateWidget<UCUI_SlotDragPreview>(GetWorld(), DragPreviewClass);
	if (!PreviewWidget) return;
	

	FItemStructure* ItemData = InventorySlot->GetItemData();
	if (!ItemData) return;

	PreviewWidget->SetImage(ItemData->Thumbnail);
	dragDropOperation->DefaultDragVisual = PreviewWidget;
	dragDropOperation->Payload = this;

}

bool UCUI_InventorySlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	if (!InOperation || !InOperation->Payload) return false;

	UCUI_InventorySlot* sourceSlot = Cast<UCUI_InventorySlot>(InOperation->Payload);
	if (!sourceSlot || !sourceSlot->InventorySlot) return false;

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	if (!controller) return false;

	ACPlayerState* state= controller->GetPlayerState<ACPlayerState>();
	if (!state) return false;

	if (!state->GetInventoryComponent()) return false;

	if (state->GetInventoryComponent()->CheckInventoryFull())return false;

	return state->GetInventoryComponent()->SwapSlots(sourceSlot->InventorySlot, InventorySlot);
}
