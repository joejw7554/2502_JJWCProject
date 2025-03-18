#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CGameMode.generated.h"

UCLASS()
class JJW_PROJECT_API ACGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACGameMode();

public:
	FORCEINLINE class UCItemFactoryComponent* GetItemFactory() { return ItemFactoryComponent; }

protected:
	UPROPERTY(VisibleAnywhere)
	class UCItemFactoryComponent* ItemFactoryComponent;
};
