#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "../Weapons/CWeaponStructure.h"
#include "CWeaponComponent.generated.h"

UENUM()
enum class EStateType :uint8
{
	UnArmed = 0, Armed, DoingAction
};

UCLASS()
class JJW_PROJECT_API UCWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCWeaponComponent();

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE bool IsUnArmed() { return CurrentState == EStateType::UnArmed; }

private:
	class UCWeaponAsset* GetWeaponAsset(EWeaponType InType);
	class UCEquipment* GetEquipment();
	class ACWeaponBase* GetWeapon();

public:
	void SetKatanaMode();

private:
	void SetMode(EWeaponType InType);

	void ChangeWeaponType(EWeaponType InType);
	void ChangeState(EStateType InType);

private:
	void Begin_Equip();

	void End_Equip();
	

private:
	UPROPERTY(EditDefaultsOnly, Category="Weapon Assets")
	TArray<class UCWeaponAsset*> WeaponAssets;

private:
	ACharacter* OwnerCharacter;
	
	EWeaponType CurrentWeaponType = EWeaponType::Max;//

	EStateType CurrentState= EStateType::UnArmed;
};
