#include "CSkillComponent.h"
#include "Animation/AnimMontage.h"

UCSkillComponent::UCSkillComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UCSkillComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UCSkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

