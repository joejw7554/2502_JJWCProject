#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CPlayerState.generated.h"

UCLASS()
class JJW_PROJECT_API ACPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ACPlayerState();

private:
	UPROPERTY(VisibleAnywhere)
	class UCInventoryComponent* InventoryComponent;
};
