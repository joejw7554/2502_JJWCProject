#include "Enemy/CEnemyBase.h"
#include "Framework/CGameMode.h"
#include "Components/CItemFactoryComponent.h"
#include "Item/CItemBase.h"
#include "Components/SkeletalMeshComponent.h"
ACEnemyBase::ACEnemyBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add("Enemy");

	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
}

void ACEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACEnemyBase::DropItem()
{
	if (!DropTable) return;

	ACGameMode* gameMode = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
	if (!gameMode) return;

	const TMap<FName, uint8*> map= DropTable->GetRowMap();
	if (map.IsEmpty()) return;

	for (const TPair<FName, uint8*>& pair : map)
	{
		FItemDropTable* data = (FItemDropTable*)pair.Value;

		UE_LOG(LogTemp, Warning, TEXT("%f"), data->ItemDropRate);
		UE_LOG(LogTemp, Warning, TEXT("%d"), data->SpawnCount);

		for (int32 i = 0; i < data->SpawnCount; ++i)
		{
			float random = FMath::FRandRange(0.0f, 1.0f);

			if (random <= data->ItemDropRate) 
			ACItemBase* item = gameMode->GetItemFactory()->GetDropItem(data->ItemID, GetActorLocation()+FVector(0,i*100.f,0), FRotator::ZeroRotator);
		}
	}
}
