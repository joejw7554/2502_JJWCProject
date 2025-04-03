#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Stats.generated.h"

UCLASS()
class JJW_PROJECT_API UCUI_Stats : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* StrengthValueText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DefenseValueText;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* StrengthDecrementButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* StrengthIncrementButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* DefenseDecrementButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* DefenseIncrementButton;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* EXPBar;
};
