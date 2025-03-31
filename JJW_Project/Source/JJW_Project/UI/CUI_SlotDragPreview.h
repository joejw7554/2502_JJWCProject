#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_SlotDragPreview.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_SlotDragPreview : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;
private:
	UPROPERTY(meta = (BindWidget))
	class UImage* SlotItemImage;
	
	UPROPERTY()
	int32 ItemID;
};
