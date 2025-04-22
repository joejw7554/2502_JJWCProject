#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HPBarInteraction.generated.h"

UINTERFACE(MinimalAPI)
class UHPBarInteraction : public UInterface
{
	GENERATED_BODY()
};

class JJW_PROJECT_API IHPBarInteraction
{
	GENERATED_BODY()

public:
	virtual void ShowHPBar() {}
	virtual void HideHPBar() {}
};
