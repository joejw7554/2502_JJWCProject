#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"


UENUM()
enum class EState : uint8
{
	Idle=0, Damaged, Dodge, Attack, Max
};

UCLASS()
class JJW_PROJECT_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStateComponent();

protected:
	virtual void BeginPlay() override;

};
