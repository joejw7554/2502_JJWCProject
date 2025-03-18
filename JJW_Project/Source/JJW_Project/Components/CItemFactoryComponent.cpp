#include "Components/CItemFactoryComponent.h"
#include "Item/CItemBase.h"

UCItemFactoryComponent::UCItemFactoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	ConstructorHelpers::FObjectFinder<UDataTable> itemTable(L"/Script/Engine.DataTable'/Game/Blueprints/Items/DT_ItemTable.DT_ItemTable'");
	if (itemTable.Succeeded())
		ItemTable = itemTable.Object;

}

ACItemBase* UCItemFactoryComponent::GetDropItem(const uint8 ID, FVector InLocation, FRotator InRotation)
{
	if (!ItemTable) return nullptr;

	const TMap<FName, uint8*> row = ItemTable->GetRowMap();

	for (TPair<FName, uint8*> pair : row)
	{
		FItemStructure* data = (FItemStructure*)pair.Value;

		if (data->ItemID == ID)
			return GetWorld()->SpawnActor<ACItemBase>(data->ItemClass, InLocation, InRotation);
	}


	return nullptr;
}

void UCItemFactoryComponent::BeginPlay()
{
	Super::BeginPlay();
}