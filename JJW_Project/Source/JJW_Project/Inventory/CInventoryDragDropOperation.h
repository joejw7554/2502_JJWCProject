#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "CInventoryDragDropOperation.generated.h"

UCLASS()
class JJW_PROJECT_API UCInventoryDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()

public:
	void Dragged_Implementation(const FPointerEvent& PointerEvent);
	void Drop_Implementation(const FPointerEvent& PointerEvent);
	void InitializeDragDropOperation(class UCInventorySlot* InSlot);

protected:
	UPROPERTY()
	class UCInventorySlot* DraggedSlot;

	UPROPERTY()
	class UCUI_SlotDragPreview* DragPreview;

	class UCUI_InventorySlot* Test;
};
