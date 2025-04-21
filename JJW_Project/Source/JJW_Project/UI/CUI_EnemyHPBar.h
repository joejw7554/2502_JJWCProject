#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_EnemyHPBar.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_EnemyHPBar : public UUserWidget
{
	GENERATED_BODY()
	

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* EnemyHPBar;

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void OnEnemyHealthUIUpdate(float InValue);


	void ShowHPBar();
	void HideHPBar();

};
