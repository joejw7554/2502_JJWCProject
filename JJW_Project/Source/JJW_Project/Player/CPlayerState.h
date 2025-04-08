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
	class UCInventoryComponent* GetInventoryComponent() { return InventoryComponent; }

	class UCStatComponent* GetStatComponent() { return StatComponent; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	class UCInventoryComponent* InventoryComponent;

	UPROPERTY(VisibleAnywhere)
	class UCStatComponent* StatComponent;

	UPROPERTY()
	class ACPlayer* OwnerCharacter;
};
