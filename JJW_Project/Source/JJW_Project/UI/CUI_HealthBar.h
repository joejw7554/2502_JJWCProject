#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_HealthBar.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_HealthBar : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void OnHealthBarChanged(float HealthPercent);
	
	
};
