#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Player/PlayerStatus.h"
#include "Status.generated.h"

UINTERFACE(MinimalAPI)
class UStatus : public UInterface
{
	GENERATED_BODY()
};

class JJW_PROJECT_API IStatus
{
	GENERATED_BODY()

public:
	virtual EStatus GetStatus()=0;
	virtual void SetStatus(EStatus InStatus) = 0;
};
