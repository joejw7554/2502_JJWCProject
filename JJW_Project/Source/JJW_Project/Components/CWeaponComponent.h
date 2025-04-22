#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Weapons/CWeaponStructure.h"
#include "../Weapons/CSkillStructure.h"
#include "../Weapons/CWeaponAsset.h"
#include "CWeaponComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWeaponTypeChanged, EWeaponType, InPrevType, EWeaponType, InNewType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAIWeaponEquipped, bool, bIsArmed);


USTRUCT()
struct FWeaponData
{
	GENERATED_BODY()
public:
	FWeaponData() : Weapon(nullptr), WeaponType(EWeaponType::Max) {}
	FWeaponData(ACWeaponBase* InWeapon, EWeaponType InType) : Weapon(InWeapon), WeaponType(InType) {}

	ACWeaponBase* GetWeapon() { return Weapon; }
	EWeaponType GetWeaponType() { return WeaponType; }

private:
	UPROPERTY()
	ACWeaponBase* Weapon;

	UPROPERTY()
	EWeaponType WeaponType;
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

	void AttachWeaponToSocket(EWeaponType WeaponType);
	void AttachWeaponToHand(EWeaponType WeaponType);

	/////////////////////////
public:
	FORCEINLINE bool IsUnArmed() { return CurrentWeaponType == EWeaponType::Max; }

public:
	EWeaponType GetCurrentWeaponType() { return CurrentWeaponType; }

	class ACWeaponBase* GetWeapon(EWeaponType InType)
	{
		ACWeaponBase* weapon = WeaponData[(int8)InType].GetWeapon();
		return weapon;
	}
	class ACWeaponBase* GetCurrentWeapon()
	{
		return GetWeapon(CurrentWeaponType);
	}

	class UCWeaponAsset* GetWeaponAsset(EWeaponType InType)
	{
		for (UCWeaponAsset* asset : WeaponAssets)
		{
			if (InType == asset->GetWeaponType())
				return asset;
		}
		return nullptr;
	}

	FWeaponTypeChanged OnWeaponTypeChanged;
	FAIWeaponEquipped OnAIWeaponStateChanged;

	//무기 관련함수들
public:
	void SetKatanaMode();
	void TestWeaponMode();

	void DoSkill(ESkillKey InKey);

protected:
	void SetUnarmedMode();
	

public:
	void ResetComboIndex() { CurrentComboIndex = 1; }
	void IncreaseComboIndex() { ++CurrentComboIndex; }
	void SetEnableCombo() { bEnableCombo = true; }
	void SetDisableCombo() { bEnableCombo = false; }
	void EnableWeaponCollision();
	void DisableWeaponCollision();

public:
	

protected:
	ACharacter* GetOwnerCharacter() { return OwnerCharacter; }


protected:
	//애니메이션 관련 함수
	FORCEINLINE bool IsPlayingAnimAction();

	//무기관련 함수들////////////////////////////////////////
protected:
	void SetMode(EWeaponType WeaponType);// 타입 바꾸기전 명시하는 함수들
	virtual void ChangeWeaponType(EWeaponType WeaponType); //무기 타입 바꾸는용도
	void ActivateWeapon(EWeaponType WeaponType);
	void DeActivateWeapon(EWeaponType WeaponType);



	///장착관련 함수들//////////////////////////////////////////////
protected:
	void Equip(EWeaponType WeaponType);
	void UnEquip(EWeaponType WeaponType);

	//NotifyState의 Begin 과 End 에서 호출할 함수들
public:
	void Begin_Equip();
	void End_Equip();
	

protected:
	UPROPERTY(EditDefaultsOnly, Category="Weapon Assets")
	TArray<class UCWeaponAsset*> WeaponAssets;

protected:
	ACharacter* OwnerCharacter;

	EWeaponType CurrentWeaponType = EWeaponType::Max;

	class UCMovementComponent* MovementComp;

	int8 CurrentComboIndex = 1;

	ESkillKey CurrentSkillKey;
	bool bEnableCombo = false;

	UPROPERTY()
	TArray<FWeaponData> WeaponData;
};
