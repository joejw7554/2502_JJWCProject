#include "Components/CDamageUIComponent.h"
#include "UI/CUI_Damage.h"

UCDamageUIComponent::UCDamageUIComponent()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(L"/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/WBP_CUIDamage.WBP_CUIDamage_C'");

	if (WidgetClassFinder.Succeeded())
	{
		SetWidgetClass(WidgetClassFinder.Class);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WidgetClassFinder failed"));
	}


	SetWidgetSpace(EWidgetSpace::Screen);
}