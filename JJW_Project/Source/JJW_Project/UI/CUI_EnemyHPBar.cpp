#include "UI/CUI_EnemyHPBar.h"
#include "Components/ProgressBar.h"

void UCUI_EnemyHPBar::NativeConstruct()
{
	Super::NativeConstruct();

}

void UCUI_EnemyHPBar::OnEnemyHealthUIUpdate(float InValue)
{
	if (EnemyHPBar)
	{
		EnemyHPBar->SetPercent(InValue);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HPBar is not valid"));
	}
}

void UCUI_EnemyHPBar::ShowHPBar()
{
	if (EnemyHPBar)
	{
		EnemyHPBar->SetVisibility(ESlateVisibility::Visible);
	}
	
}

void UCUI_EnemyHPBar::HideHPBar()
{
	if (EnemyHPBar)
	{
		EnemyHPBar->SetVisibility(ESlateVisibility::Hidden);
	}

}


