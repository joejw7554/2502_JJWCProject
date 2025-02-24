#include "CStateComponent.h"
#include "../Player/CPlayer.h"

UCStateComponent::UCStateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UCStateComponent::SetIdleMode()
{
	ChangeState(CurrentState, EState::Idle);
}

void UCStateComponent::SetAttackMode()
{
	ChangeState(CurrentState, EState::Attack);

}

void UCStateComponent::SetDodgeMode()
{
	ChangeState(CurrentState, EState::Dodge);

}

void UCStateComponent::SetDamagedMode()
{
	ChangeState(CurrentState, EState::Damaged);

}

void UCStateComponent::SetDeadMode()
{
	ChangeState(CurrentState, EState::Dead);

}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACPlayer>(GetOwner());
	
}

void UCStateComponent::ChangeState(EState InPrevState, EState InNewState)
{
	EState PrevState = InPrevState;
	CurrentState = InNewState;

	if (OnStateChange.IsBound())
		OnStateChange.Broadcast(PrevState, CurrentState);

}
