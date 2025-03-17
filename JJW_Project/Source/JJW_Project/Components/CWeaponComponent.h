#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "../Weapons/CWeaponStructure.h"
#include "../Weapons/CSkillStructure.h"
#include "CWeaponComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWeaponTypeChanged, EWeaponType, InPrevType, EWeaponType, InNewType);


UCLASS()
class JJW_PROJECT_API UCWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCWeaponComponent();

protected:
	virtual void BeginPlay() override;
	void SpawnWeapons(class UCWeaponAsset* asset);

	void AttachWeaponToSocket(EWeaponType WeaponType);
	void AttachWeaponToHand(EWeaponType WeaponType);

	/////////////////////////
public:
	FORCEINLINE bool IsUnArmed() { return CurrentWeaponType == EWeaponType::Max; }

public:
	EWeaponType GetCurrentWeaponType() { return CurrentWeaponType; }
	class ACWeaponBase* GetCurrentWeapon();

	FWeaponTypeChanged OnWeaponTypeChanged;

	//무기 관련함수들
public:
	void SetKatanaMode();
	void TestWeaponMode();

	void DoSkill(ESkillKey InKey);

private:
	void SetUnarmedMode();
	

public:
	void ResetComboIndex() { CurrentComboIndex = 1; }
	void IncreaseComboIndex() { ++CurrentComboIndex; }
	void SetEnableCombo() { bEnableCombo = true; }
	void SetDisableCombo() { bEnableCombo = false; }
	void EnableWeaponCollision();
	void DisableWeaponCollision();

public:
	class UCWeaponAsset* GetWeaponAsset(EWeaponType WeaponType);

private:
	//애니메이션 관련 함수
	FORCEINLINE bool IsPlayingAnimAction();

	//무기관련 함수들////////////////////////////////////////
private:
	void SetMode(EWeaponType WeaponType);// 타입 바꾸기전 명시하는 함수들

	void ChangeWeaponType(EWeaponType WeaponType); //무기 타입 바꾸는용도

	void ActivateWeapon(EWeaponType WeaponType);
	void DeActivateWeapon(EWeaponType WeaponType);



	///장착관련 함수들//////////////////////////////////////////////
private:
	void Equip(EWeaponType WeaponType);
	void UnEquip(EWeaponType WeaponType);

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

	class UCMovementComponent* MovementComp;

	int8 CurrentComboIndex = 1;

	ESkillKey CurrentSkillKey;
	bool bEnableCombo = false;
};
