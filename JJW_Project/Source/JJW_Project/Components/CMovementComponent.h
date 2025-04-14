#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "CMovementComponent.generated.h"


UCLASS()
class JJW_PROJECT_API UCMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCMovementComponent();

	FORCEINLINE  void EnableMovement() { bCanMove = true; }
	FORCEINLINE  void DisableMovment() { bCanMove = false; }
	FORCEINLINE bool CanMove() { return bCanMove; }
private:

	bool bCanMove = true;
	
};
