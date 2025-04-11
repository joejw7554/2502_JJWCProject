#pragma once

#include "CoreMinimal.h"
#include "Enemy/CEnemyBase.h"
#include "CEnemyBase_Katana.generated.h"

UCLASS()
class JJW_PROJECT_API ACEnemyBase_Katana : public ACEnemyBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SpawnWeapon() override;
};
