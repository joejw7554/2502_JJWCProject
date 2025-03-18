#include "Item/CItemBase_Potion_HP.h"

ACItemBase_Potion_HP::ACItemBase_Potion_HP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACItemBase_Potion_HP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACItemBase_Potion_HP::BeginPlay()
{
	Super::BeginPlay();
}

void ACItemBase_Potion_HP::UseItem()
{
}
