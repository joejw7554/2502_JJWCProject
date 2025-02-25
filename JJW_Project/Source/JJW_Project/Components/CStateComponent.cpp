#include "CStateComponent.h"
#include "../Player/CPlayer.h"

UCStateComponent::UCStateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

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
