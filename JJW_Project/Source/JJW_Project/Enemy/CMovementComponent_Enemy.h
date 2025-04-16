#pragma once

#include "CoreMinimal.h"
#include "Components/CMovementComponent.h"
#include "CMovementComponent_Enemy.generated.h"

UCLASS()
class JJW_PROJECT_API UCMovementComponent_Enemy : public UCMovementComponent
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;



};
