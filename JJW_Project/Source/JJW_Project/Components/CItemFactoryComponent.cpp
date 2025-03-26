#include "Components/CItemFactoryComponent.h"
#include "Item/CItemBase.h"
#include "Item/CDropItemDataManager.h"

UCItemFactoryComponent::UCItemFactoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	ConstructorHelpers::FObjectFinder<UDataTable> itemTable(L"/Script/Engine.DataTable'/Game/Blueprints/Items/DT_ItemTable.DT_ItemTable'");
	if (itemTable.Succeeded())
		ItemTable = itemTable.Object;

	ConstructorHelpers::FClassFinder<ACDropItemDataManager> dataManagerClass(L"/Script/Engine.Blueprint'/Game/Blueprints/Items/BP_CDropItemDataManager.BP_CDropItemDataManager_C'");
	if (dataManagerClass.Succeeded())
		DataManagerClass = dataManagerClass.Class;

}

void UCItemFactoryComponent::CreateDropItem(const EEnemyType InType, FVector InLocation, float InLocationVariation)
{
	if (!DataManager) return;

	const TMap<FName, uint8*> itemTableRow = ItemTable->GetRowMap();
	const TMap<FName, uint8*> dropTableRow = DataManager->GetDropTable(InType)->GetRowMap();

	for (TPair<FName, uint8*> pair : itemTableRow)
	{
		for (TPair<FName, uint8*> dropPair : dropTableRow)
		{
			FItemStructure* itemData = (FItemStructure*)pair.Value;
			FItemDropTable* dropData = (FItemDropTable*)dropPair.Value;

			if (itemData->ItemID == dropData->ItemID)
			{
				int8 count = dropData->SpawnCount;
				for (int i = 0; i < count; i++)
				{
					float dropRate = FMath::FRandRange(0.0f, 1.0f);
					if (dropRate <= dropData->DropRate)
					{
						ACItemBase* item = GetWorld()->SpawnActor<ACItemBase>(itemData->ItemClass, InLocation, FRotator::ZeroRotator);
						item->InitializeItemData(item, *itemData);

						//Set Random Location within the Character's CapsuleComponent Range
						{
							float randomX = FMath::FRandRange(-InLocationVariation, InLocationVariation);
							float randomY = FMath::FRandRange(-InLocationVariation, InLocationVariation);
							InLocation.X += randomX;
							InLocation.Y += randomY;
							item->SetActorLocation(InLocation);
						}
					}
				}
				break;
			}
		}

	}
}

void UCItemFactoryComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!DataManagerClass) return;

	for (AActor* actor : GetWorld()->GetCurrentLevel()->Actors)
	{
		if (actor->IsA(DataManagerClass))
		{
			if (actor) 
			DataManager = Cast<ACDropItemDataManager>(actor);
			break;
		}
	}
}