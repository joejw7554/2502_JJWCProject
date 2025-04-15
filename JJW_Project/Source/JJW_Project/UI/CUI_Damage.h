
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Damage.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_Damage : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void PlayDamageAnimation(float DamageAmount);

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DamageText;

	UPROPERTY( meta=(BindWidgetAnim), Transient)
	class UWidgetAnimation* DamageAnimation;
};
