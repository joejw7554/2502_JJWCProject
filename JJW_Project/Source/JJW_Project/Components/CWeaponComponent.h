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
	void SpawnWeapons(class UCWeaponAsset* asset);
	void AttachWeaponToSocket(EWeaponType InWeaponType);


	/////////////////////////
public:
	FORCEINLINE bool IsUnArmed() { return CurrentState == EStateType::UnArmed; }
	FORCEINLINE bool IsArmed() { return CurrentState == EStateType::Armed; }


	//Player Key에따라 불릴 함수들
public:
	void SetKatanaMode();

private:
	class UCWeaponAsset* GetWeaponAsset(EWeaponType InType);

private:
	void SetMode(EWeaponType InWeaponType);// 타입 바꾸기전 명시하는 함수들

	void ChangeWeaponType(EWeaponType InWeaponType); //무기 타입 바꾸는용도
	void ChangeState(EStateType InStateType); //


	void EquipSetup();

	//NotifyState의 Begin 과 End 에서 호출할 함수들
	void Begin_Equip();
	void End_Equip();
	

/// //////////////////////////////
private:
	UPROPERTY(EditDefaultsOnly, Category="Weapon Assets")
	TArray<class UCWeaponAsset*> WeaponAssets;

private:
	ACharacter* OwnerCharacter;
	
	EWeaponType CurrentWeaponType = EWeaponType::Max;

	EStateType CurrentState= EStateType::UnArmed;

	class UCMovementComponent* MovementComp;
};
