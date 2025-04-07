#include "UI/CUI_Stats.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

#include "Player/CPlayerState.h"
#include "Stats/CStatComponent.h"


void UCUI_Stats::ToggleStats()
{
	if (IsVisible())
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		SetVisibility(ESlateVisibility::Visible);
	}
}

void UCUI_Stats::NativeConstruct()
{
	Super::NativeConstruct();

	SetVisibility(ESlateVisibility::Hidden);

	CloseButton->OnClicked.AddDynamic(this, &UCUI_Stats::ToggleStats);

	StrengthIncrementButton->OnClicked.AddDynamic(this, &UCUI_Stats::OnStrengthIncrementation);
	StrengthDecrementButton->OnClicked.AddDynamic(this, &UCUI_Stats::OnStrengthDecrementation);

	DefenseIncrementButton->OnClicked.AddDynamic(this, &UCUI_Stats::OnDefenseIncrementation);
	DefenseDecrementButton->OnClicked.AddDynamic(this, &UCUI_Stats::OnDefenseDecrementation);


	ACPlayerState* playerState = GetWorld()->GetFirstPlayerController()->GetPlayerState<ACPlayerState>();
	if (!playerState) return;

	StatComponent = playerState->GetStatComponent();
	if (!StatComponent) return;

	OnStrengthIncremented.AddDynamic(StatComponent, &UCStatComponent::IncrementStat);
	OnStrengthDecremented.AddDynamic(StatComponent, &UCStatComponent::DecrementStat);
	OnDefenseIncremented.AddDynamic(StatComponent, &UCStatComponent::IncrementStat);
	OnDefenseDecremented.AddDynamic(StatComponent, &UCStatComponent::DecrementStat);

	StatComponent->OnStatPointUpdate.AddDynamic(this, &UCUI_Stats::OnUpdateAvailableStatPoint);
	

	StatUIInitialization();
}

void UCUI_Stats::StatUIInitialization()
{
	StrengthValueText->SetText(FText::AsNumber(StatComponent->GetStatStructure().Strength));
	DefenseValueText->SetText(FText::AsNumber(StatComponent->GetStatStructure().Defense));
}

void UCUI_Stats::OnStrengthIncrementation()
{
	if(OnStrengthIncremented.IsBound())
		OnStrengthIncremented.Broadcast(FName("Strength"));

	StrengthValueText->SetText(FText::AsNumber(StatComponent->GetStatStructure().Strength));
}

void UCUI_Stats::OnStrengthDecrementation()
{
	if (OnStrengthDecremented.IsBound())
		OnStrengthDecremented.Broadcast(FName("Strength"));

	StrengthValueText->SetText(FText::AsNumber(StatComponent->GetStatStructure().Strength));
}

void UCUI_Stats::OnDefenseIncrementation()
{
	if (OnDefenseIncremented.IsBound())
		OnDefenseIncremented.Broadcast(FName("Defense"));

	DefenseValueText->SetText(FText::AsNumber(StatComponent->GetStatStructure().Defense));

}

void UCUI_Stats::OnDefenseDecrementation()
{
	if (OnDefenseDecremented.IsBound())
		OnDefenseDecremented.Broadcast(FName("Defense"));

	DefenseValueText->SetText(FText::AsNumber(StatComponent->GetStatStructure().Defense));
}

void UCUI_Stats::OnUpdateAvailableStatPoint(uint8 InValue)
{
	StatPointsText->SetText(FText::AsNumber(InValue));
}







