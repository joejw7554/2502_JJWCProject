#include "Inventory/CInventoryDragDropOperation.h"
#include "Blueprint/UserWidget.h"
#include "UI/CUI_SlotDragPreview.h"
#include "Inventory/CInventorySlot.h"
#include "UI/CUI_InventorySlot.h"

void UCInventoryDragDropOperation::Dragged_Implementation(const FPointerEvent& PointerEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Dragged_Implementation"));
}

void UCInventoryDragDropOperation::Drop_Implementation(const FPointerEvent& PointerEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Drop_Implementation"));

	//DragPreview = nullptr;
}


void UCInventoryDragDropOperation::InitializeDragDropOperation(UCInventorySlot* InSlot)
{
    // 프리뷰 위젯 생성
    if (!DragPreviewClass) return;
    UCUI_SlotDragPreview* PreviewWidget = CreateWidget<UCUI_SlotDragPreview>(GetWorld(), DragPreviewClass);
    if (PreviewWidget && InSlot->GetItemData())
    {
        PreviewWidget->SetImage(InSlot->GetItemData()->Thumbnail);
    }

    // 드래그 작업 초기화
    DefaultDragVisual = PreviewWidget;
    Payload = (UObject*)InSlot;

    UE_LOG(LogTemp, Warning, TEXT("DragDropOperation Initialized with Preview Widget"));
}


