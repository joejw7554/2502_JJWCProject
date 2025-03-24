// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Inventory.h"
#include "CUI_MainHUD.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_MainHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void ToggleInventoryUI(bool bShow);
	UCUI_Inventory* GetInventoryWidget() { return InventoryWidget; }


private:
	UPROPERTY(meta = (BindWidget))
	 UCUI_Inventory* InventoryWidget;

};
