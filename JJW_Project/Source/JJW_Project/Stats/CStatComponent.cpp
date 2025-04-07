#include "Stats/CStatComponent.h"

UCStatComponent::UCStatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCStatComponent::IncrementStat(FName InStat)
{

	if (AvailableStatPoint <= 0) return;


	if (InStat == "Strength")
	{
		StatStructure.Strength += 1.f;
		AvailableStatPoint--;
	}
	else if (InStat == "Defense")
	{
		StatStructure.Defense += 1.f;
		AvailableStatPoint--;
	}

	if (OnStatPointUpdate.IsBound())
		OnStatPointUpdate.Broadcast(AvailableStatPoint);
}

void UCStatComponent::DecrementStat(FName InStat)
{
	if (AvailableStatPoint <= 0) return;

	if (InStat == "Strength")
	{
		StatStructure.Strength = FMath::Clamp(StatStructure.Strength, 0.f, StatStructure.Strength);
		AvailableStatPoint++;
	}
	else if (InStat == "Defense")
	{
		StatStructure.Defense = FMath::Clamp(StatStructure.Defense, 0.f, StatStructure.Defense);
		AvailableStatPoint++;
	}

	if (OnStatPointUpdate.IsBound())
		OnStatPointUpdate.Broadcast(AvailableStatPoint);
}

void UCStatComponent::SetAvailableStatPoint(uint8 InStatPoint)
{
	AvailableStatPoint = InStatPoint;

	if (OnStatPointUpdate.IsBound())
		OnStatPointUpdate.Broadcast(AvailableStatPoint);
}


void UCStatComponent::BeginPlay()
{
	Super::BeginPlay();

	
	OnStatPointUpdate.Broadcast(AvailableStatPoint);
}

void UCStatComponent::AddPlayerEXP(float InEXP)
{
	CurrentEXP += InEXP;
	if (CurrentEXP >= MaxEXP)
	{
		CurrentLevel++;
		SetAvailableStatPoint(LevelUpProvidingStatPoint);
		ExtendMaxEXP();
	}
}

void UCStatComponent::ExtendMaxEXP()
{
	CurrentEXP = CurrentEXP - MaxEXP;
	MaxEXP = MaxEXP * MaxEXPIncrement;
}
