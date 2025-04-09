#include "UI/CUI_HealthBar.h"
#include "Components/ProgressBar.h"
#include "Player/CPlayer.h"

void UCUI_HealthBar::NativeConstruct()
{
	Super::NativeConstruct();

}

void UCUI_HealthBar::OnHealthBarChanged(float HealthPercent)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(HealthPercent);
	}
}
