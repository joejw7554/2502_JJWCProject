#include "Components/CItemFactoryComponent.h"
#include "Item/CItemBase.h"

UCItemFactoryComponent::UCItemFactoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

ACItemBase* UCItemFactoryComponent::GetItem(EItemType InType)
{
	ACItemBase* ItemToSpawn = nullptr;

	if (ItemList.Contains(InType))
	{
		FItemStructure ItemStructure = ItemList[InType];
		ItemToSpawn = GetWorld()->SpawnActor<ACItemBase>(ItemStructure.ItemClass);
		return ItemToSpawn;
	}

	return nullptr;
}


void UCItemFactoryComponent::BeginPlay()
{
	Super::BeginPlay();
}