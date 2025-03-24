#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Inventory.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_Inventory : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void ToggleInventory();

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* SlotGridPanel;

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseButton;

	UPROPERTY()
	TArray<class UCUI_InventorySlot*> InventorySlots;
	
};
