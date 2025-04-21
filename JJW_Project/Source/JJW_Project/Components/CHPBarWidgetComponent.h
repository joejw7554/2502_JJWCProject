#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "CHPBarWidgetComponent.generated.h"

UCLASS()
class JJW_PROJECT_API UCHPBarWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
public:
	UCHPBarWidgetComponent();
protected:
	virtual void BeginPlay() override;
};
