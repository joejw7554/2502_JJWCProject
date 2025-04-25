#include "UI/CUI_HealthBar.h"
#include "Components/ProgressBar.h"
#include "Player/CPlayer.h"
#include "Components/TextBlock.h"

void UCUI_HealthBar::NativeConstruct()
{
	Super::NativeConstruct();

	/*ACPlayer* player = Cast<ACPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player)
	{
		player->OnHealthBarUpdate.AddDynamic(this, &UCUI_HealthBar::OnHealthBarChanged);
		player->OnHealthBarUpdate.AddDynamic(this, &UCUI_HealthBar::OnPlayerHealthValueTextUpdate);
	}*/


}

void UCUI_HealthBar::OnHealthBarChanged(float HealthPercent)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(HealthPercent);
	}
}

void UCUI_HealthBar::OnPlayerHealthValueTextUpdate(float HealthValue)
{
	UE_LOG(LogTemp, Warning, TEXT("UCUI_HealthBar::OnPlayerHealthValueTextUpdate: %f"), HealthValue);
	if (HealthText)
	{
		int32 HealthValueInt = FMath::RoundToInt(HealthValue * 100);
		HealthText->SetText(FText::AsNumber(HealthValueInt));
	}
}

