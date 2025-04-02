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
	if (!InSlot) return;
	DraggedSlot = InSlot;

	if (!DraggedSlot) return;
	if (!DragPreview)
	{
		UWorld* World = GetWorld();
		if (!World) return;
			

		DragPreview = CreateWidget<UCUI_SlotDragPreview>(GetWorld(), UCUI_SlotDragPreview::StaticClass());
		//이거 StaticClass 쓰지말고 블루프린트로 만들어서 쓰자 TSubClassOf로 받아서 만들어서 해보자
		if (DragPreview)
		{

			if (!DraggedSlot->GetItemData()) return;

			DragPreview->SetImage(DraggedSlot->GetItemData()->Thumbnail); 
			DragPreview->AddToViewport(2);
			DefaultDragVisual = DragPreview;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("DragPreview is not created"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DragPreview is already created or not Valid"));
	}

}


