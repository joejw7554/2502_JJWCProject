#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Inventory.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_Inventory : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* SlotGridPanel;
};
