#include "UI/CUI_Damage.h"
#include "Components/TextBlock.h"

void UCUI_Damage::PlayDamageAnimation(float DamageAmount)
{
	//UE_LOG(LogTemp, Warning, TEXT("UCUI_Damage::Damage Amount: %f"), DamageAmount);

	if (DamageText)
		DamageText->SetText(FText::AsNumber(DamageAmount));

	if (DamageAnimation)
		PlayAnimation(DamageAnimation);
}
