#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy/CEnemyBase.h"
#include "CDropItemDataManager.generated.h"

UCLASS()
class JJW_PROJECT_API ACDropItemDataManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACDropItemDataManager();
	//virtual void Tick(float DeltaTime) override;

public:
	UDataTable* GetDropTable(EEnemyType InType);

protected:
	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditAnywhere)
	TMap<EEnemyType, UDataTable*> EnemyDropItemTable;

};
