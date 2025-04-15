#pragma once

#include "CoreMinimal.h"
#include "Enemy/CEnemyBase.h"
#include "CEnemyBase_Katana.generated.h"

UCLASS()
class JJW_PROJECT_API ACEnemyBase_Katana : public ACEnemyBase
{
	GENERATED_BODY()

public:
	ACEnemyBase_Katana();
	FORCEINLINE class UCWeaponComponent* GetWeaponComponent() { return WeaponComponent; }
	FORCEINLINE class UCMovementComponent_Enemy* GetMovementComponent() { return MovementComponent; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	class UCWeaponComponent* WeaponComponent;

	UPROPERTY(VisibleAnywhere)
	class UCMovementComponent_Enemy* MovementComponent;
};
