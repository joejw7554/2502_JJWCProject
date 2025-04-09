// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Inventory.h"
#include "CUI_Stats.h"
#include "CUI_MainHUD.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_MainHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FORCEINLINE void ToggleInventoryUI()
	{
		if (!GetInventoryWidget()) return;
		GetInventoryWidget()->ToggleInventory();
	}

	FORCEINLINE void ToggleStatUI()
	{
		if (!GetStatsWidget()) return;
		GetStatsWidget()->ToggleStats();
	}

	FORCEINLINE UCUI_Inventory* GetInventoryWidget() { return InventoryWidgetUI; }
	FORCEINLINE UCUI_Stats* GetStatsWidget() { return StatsWidgetUI; }
	FORCEINLINE class UCUI_HealthBar* GetHealthBarWidget() { return HealthBarUI; }

private:
	UPROPERTY(meta = (BindWidget))
	 UCUI_Inventory* InventoryWidgetUI;

	 UPROPERTY(meta = (BindWidget))
	 UCUI_Stats* StatsWidgetUI;

	 UPROPERTY(meta = (BindWidget))
	 class UCUI_HealthBar* HealthBarUI;
};
