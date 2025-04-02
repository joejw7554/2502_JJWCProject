#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "CUI_SlotDragPreview.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_SlotDragPreview : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetImage(UTexture2D* InTexture) { SlotItemImage->SetBrushFromTexture(InTexture); }

protected:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;


private:
	UPROPERTY(meta = (BindWidget))
	class UImage* SlotItemImage;
	
	UPROPERTY()
	int32 ItemID;
};
