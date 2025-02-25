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

	FORCEINLINE void SetIdleMode()	{ ChangeState(CurrentState, EState::Idle); }
	FORCEINLINE void SetAttackMode() { ChangeState(CurrentState, EState::Attack); }
	FORCEINLINE void SetDodgeMode() { ChangeState(CurrentState, EState::Dodge); }
	FORCEINLINE void SetDamagedMode() { ChangeState(CurrentState, EState::Damaged); }
	FORCEINLINE void SetDeadMode() { ChangeState(CurrentState, EState::Dead); }

	FORCEINLINE bool IsIdle() { return CurrentState == EState::Idle; }
	FORCEINLINE bool IsAttack() { return CurrentState == EState::Attack; }
	FORCEINLINE bool IsDodge() { return CurrentState == EState::Dodge; }
	FORCEINLINE bool IsDamaged() { return CurrentState == EState::Damaged; }
	FORCEINLINE bool IsDead() { return CurrentState == EState::Dead; }

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
