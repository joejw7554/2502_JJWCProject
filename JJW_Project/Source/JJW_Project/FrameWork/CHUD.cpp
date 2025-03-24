#include "FrameWork/CHUD.h"
#include "UI/CUI_MainHUD.h"


void ACHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!UI_MainHUDClass) return;

	UI_MainHUD = CreateWidget<UCUI_MainHUD>(GetWorld(), UI_MainHUDClass);
	UI_MainHUD->AddToViewport();
}

