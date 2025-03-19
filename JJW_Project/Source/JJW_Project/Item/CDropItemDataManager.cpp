#include "Item/CDropItemDataManager.h"
#include "FrameWork/CGameMode.h"
#include "Components/CItemFactoryComponent.h"


ACDropItemDataManager::ACDropItemDataManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

UDataTable* ACDropItemDataManager::GetDropTable(EEnemyType InType)
{
	if (!EnemyDropItemTable.Contains(InType)) return nullptr;

	UDataTable* dropTable = EnemyDropItemTable[InType];
	if (!dropTable) return nullptr;

	UE_LOG(LogTemp, Warning, TEXT("GetDropTable Success"));
	return dropTable;
}

void ACDropItemDataManager::BeginPlay()
{
	Super::BeginPlay();

}




