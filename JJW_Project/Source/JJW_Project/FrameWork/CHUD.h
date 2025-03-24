#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/CUI_MainHUD.h"
#include "UI/CUI_Inventory.h"
#include "CHUD.generated.h"

UCLASS()
class JJW_PROJECT_API ACHUD : public AHUD
{
	GENERATED_BODY()

public:
	UCUI_MainHUD* GetMainHUD() { return UI_MainHUD; }
	FORCEINLINE void ToggleInventory() {
		if(!UI_MainHUD)
		UE_LOG(LogTemp, Warning, TEXT("UI_MainHUD is not NULL"));

		UI_MainHUD->GetInventoryWidget()->ToggleInventory();
	
	}

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf< UCUI_MainHUD> UI_MainHUDClass;

	UPROPERTY()
	UCUI_MainHUD* UI_MainHUD;

};
