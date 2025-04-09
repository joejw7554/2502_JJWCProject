#include "FrameWork/CHUD.h"
#include "UI/CUI_MainHUD.h"
#include "Player/CPlayerState.h"
#include "Stats/CStatComponent.h"
#include "UI/CUI_HealthBar.h"
#include "Player/CPlayer.h"


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

	UCUI_HealthBar* healthUI = UI_MainHUD->GetHealthBarWidget();
	if (!healthUI) return;

	APlayerController* playerController = Cast<APlayerController>(GetOwningPlayerController());
	if(!playerController) UE_LOG(LogTemp, Warning, TEXT("ACHUD::BeginPlay: No PlayerController found"));
	if (!playerController) return;

	ACPlayer* player = Cast<ACPlayer>(playerController->GetPawn());
	if (!player) UE_LOG(LogTemp, Warning, TEXT("ACHUD::BeginPlay: No Player found"));
	if (!player) return;


	player->OnHealthBarUpdate.AddDynamic(healthUI, &UCUI_HealthBar::OnHealthBarChanged);

}
