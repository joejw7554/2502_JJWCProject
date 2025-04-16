#pragma once

#include "CoreMinimal.h"
#include "Components/CWeaponComponent.h"
#include "CWeaponComponent_Enemy.generated.h"

UCLASS()
class JJW_PROJECT_API UCWeaponComponent_Enemy : public UCWeaponComponent
{
	GENERATED_BODY()
	
protected:
	virtual void ChangeWeaponType(EWeaponType WeaponType) override;
};
