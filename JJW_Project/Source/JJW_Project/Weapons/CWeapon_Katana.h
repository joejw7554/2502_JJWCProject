#pragma once

#include "CoreMinimal.h"
#include "CWeaponBase.h"
#include "CWeapon_Katana.generated.h"

UCLASS()
class JJW_PROJECT_API ACWeapon_Katana : public ACWeaponBase
{
	GENERATED_BODY()

public:
virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;
	
};
