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

	virtual void PostInitializeComponents() override;

	FORCEINLINE UStaticMeshComponent* GetRightHandMesh() { return RightHandWeaponMesh; }
	FORCEINLINE UStaticMeshComponent* GetLeftHandMesh() { return LeftHandWeaponMesh; }

	FORCEINLINE FName GetLeftHandSocket() { return SocketName_LeftHand; }
	FORCEINLINE FName GetRightHandSocket() { return SocketName_RightHand; }

	FORCEINLINE FName GetLeftHolsterSocket() { return SocketName_HolsterLeftWeapon; }
	FORCEINLINE FName GetRightHolsterSocket() { return SocketName_HolsterRightWeapon; }


protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attachment")
	FName SocketName_HolsterLeftWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	FName SocketName_LeftHand;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	UStaticMeshComponent* RightHandWeaponMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	UStaticMeshComponent* LeftHandWeaponMesh;
};
