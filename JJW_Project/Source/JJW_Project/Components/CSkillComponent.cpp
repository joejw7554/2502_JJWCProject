

#include "CSkillComponent.h"

UCSkillComponent::UCSkillComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCSkillComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCSkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

