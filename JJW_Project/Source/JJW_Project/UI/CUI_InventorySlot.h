#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "CUI_InventorySlot.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_InventorySlot : public UUserWidget
{
	GENERATED_BODY()
public:
	void InitializeSlotWidget(int32 InSlotIndex, class UCInventorySlot* InSlot);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

private:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	UFUNCTION()
	void LeftMouseButtonClicked();
	UFUNCTION()
	void RightMouseButtonClicked();

private:
	UPROPERTY(meta=(BindWidget))
	class UImage* ItemThumnail;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ItemQuantityText;

	UPROPERTY(meta = (BindWidget))
	class UButton* SlotButton;

	UPROPERTY()
	class UCInventorySlot* InventorySlot;

	int32 SlotIndex = 0;

};
