#include "Stats/CStatComponent.h"

UCStatComponent::UCStatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCStatComponent::IncrementStat(FName InStat)
{

	if (InStat == "Strength")
	{
		StatStructure.Strength += 1.f;
	}
	else if (InStat == "Defense")
	{
		StatStructure.Defense += 1.f;
	}

}

void UCStatComponent::DecrementStat(FName InStat)
{
	if (InStat == "Strength")
	{
		StatStructure.Strength -= 1.f;
	}
	else if (InStat == "Defense")
	{
		StatStructure.Defense -= 1.f;
	}

}


void UCStatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}
