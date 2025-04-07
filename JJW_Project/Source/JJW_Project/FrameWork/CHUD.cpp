#include "FrameWork/CHUD.h"
#include "UI/CUI_MainHUD.h"
#include "Player/CPlayerState.h"
#include "Stats/CStatComponent.h"


void ACHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!UI_MainHUDClass) return;

	UI_MainHUD = CreateWidget<UCUI_MainHUD>(GetWorld(), UI_MainHUDClass);
	UI_MainHUD->AddToViewport();
}

void ACHUD::BeginPlay()
{
	Super::BeginPlay();
}

