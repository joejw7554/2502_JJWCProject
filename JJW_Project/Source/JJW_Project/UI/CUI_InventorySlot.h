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

private:
	UPROPERTY(meta = (BindWidget))
	class UImage* ItemThumnail;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemQuantityText;

	UPROPERTY(meta = (BindWidget))
	class UButton* SlotButton;

	class UCInventorySlot* InventorySlot;

	int32 SlotIndex = 0;

};
