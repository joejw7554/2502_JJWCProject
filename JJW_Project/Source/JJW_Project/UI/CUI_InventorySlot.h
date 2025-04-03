#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Item/CItemStructure.h"
#include "CUI_InventorySlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotRightClicked, int32, Index);

UCLASS()
class JJW_PROJECT_API UCUI_InventorySlot : public UUserWidget
{
	GENERATED_BODY()

public:
	FSlotRightClicked OnSlotRightClicked;


public:
	void InitializeSlotWidget(int32 InSlotIndex, class UCInventorySlot* InSlot);
	void AssignInventorySlot(class UCInventorySlot* InSlot) { InventorySlot = InSlot; }

	UFUNCTION()
	void OnSlotUpdate(class UCInventorySlot* InSlot);

	UFUNCTION()
	void OnSlotClear(class UCInventorySlot* InSlot);

protected:
	virtual void NativeConstruct() override;

private:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	

private:
	UPROPERTY(meta = (BindWidget))
	class UImage* ItemThumnail;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemQuantityText;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UCInventoryDragDropOperation> DragDropClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UCUI_SlotDragPreview> DragPreviewClass;
	
	UPROPERTY()
	class UCInventorySlot* InventorySlot;

	int32 SlotIndex = 0;

};
