#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUI_Stats.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStrengthIncrementation, FName, InStatName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStrengthDecrementation, FName, InStatName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDefenseIncrementation, FName, InStatName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDefenseDecrementation, FName, InStatName);




UCLASS()
class JJW_PROJECT_API UCUI_Stats : public UUserWidget
{
	GENERATED_BODY()

public:
	FOnStrengthIncrementation OnStrengthIncremented;
	FOnStrengthDecrementation OnStrengthDecremented;
	FOnDefenseIncrementation OnDefenseIncremented;
	FOnDefenseDecrementation OnDefenseDecremented;


public:
	UFUNCTION()
	void ToggleStats();

protected:
	virtual void NativeConstruct() override;

	void StatUIInitialization();

private:
	UFUNCTION()
	void OnStrengthIncrementation();
	UFUNCTION()
	void OnStrengthDecrementation();
	UFUNCTION()
	void OnDefenseIncrementation();
	UFUNCTION()
	void OnDefenseDecrementation();

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

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseButton;

	UPROPERTY()
	class UCStatComponent* StatComponent;
};
