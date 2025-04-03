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
