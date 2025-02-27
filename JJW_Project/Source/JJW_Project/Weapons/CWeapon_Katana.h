#pragma once

#include "CoreMinimal.h"
#include "CWeaponBase.h"
#include "CWeapon_Katana.generated.h"

UCLASS()
class JJW_PROJECT_API ACWeapon_Katana : public ACWeaponBase
{
	GENERATED_BODY()

public:
	ACWeapon_Katana();

protected:
	virtual void BeginPlay() override;


protected:
	UPROPERTY(VisibleAnywhere)
	FName SocketName_ExtraWeaponHolster;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* LeftWeaponMesh;
};
