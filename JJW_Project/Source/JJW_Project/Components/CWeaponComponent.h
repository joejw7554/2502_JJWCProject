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
	void AttachWeaponToHand(EWeaponType InWeaponType);



	/////////////////////////
public:
	FORCEINLINE bool IsUnArmed() { return CurrentState == EStateType::UnArmed; }
	FORCEINLINE bool IsArmed() { return CurrentState == EStateType::Armed; }


	//종류별 무기 장착 함수들///////////////////////////////////////////
public:
	void SetKatanaMode();



private:
	class UCWeaponAsset* GetWeaponAsset(EWeaponType InType);

	//애니메이션 관련 함수들
	FORCEINLINE bool IsPlayingAnimAction();



	//무기관련 함수들////////////////////////////////////////
private:
	void SetMode(EWeaponType InWeaponType);// 타입 바꾸기전 명시하는 함수들

	void ChangeWeaponType(EWeaponType InWeaponType); //무기 타입 바꾸는용도
	void ChangeState(EStateType InStateType); 

	void ActivateWeapon(EWeaponType WeaponType);
	void DeActivateWeapon(EWeaponType WeaponType);


	///장착관련 함수들//////////////////////////////////////////////
private:
	void Equip();
	void UnEquip();

	//NotifyState의 Begin 과 End 에서 호출할 함수들
public:
	void Begin_Equip();
	void End_Equip();
	

private:
	UPROPERTY(EditDefaultsOnly, Category="Weapon Assets")
	TArray<class UCWeaponAsset*> WeaponAssets;

private:
	ACharacter* OwnerCharacter;

	EWeaponType CurrentWeaponType = EWeaponType::Max;

	EStateType CurrentState= EStateType::UnArmed;

	class UCMovementComponent* MovementComp;
};
