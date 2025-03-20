#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_InventorySlot.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_InventorySlot : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta=(BindWidget))
	class UImage* ItemThumnail;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ItemQuantityText;

};
