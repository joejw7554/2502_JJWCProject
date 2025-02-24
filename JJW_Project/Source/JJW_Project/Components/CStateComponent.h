#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"


UENUM()
enum class EState : uint8
{
	Idle = 0, Attack, Dodge, Damaged, Dead, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateChange, EState, InPrevState, EState, InNewState);

UCLASS()
class JJW_PROJECT_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCStateComponent();

	void SetIdleMode();
	void SetAttackMode();
	void SetDodgeMode();
	void SetDamagedMode();
	void SetDeadMode();

protected:
	virtual void BeginPlay() override;

private:
	void ChangeState(EState InPrevState, EState InNewState);

private:
	EState CurrentState = EState::Idle;

	class ACPlayer* Owner;

public:
	FStateChange OnStateChange;

};
