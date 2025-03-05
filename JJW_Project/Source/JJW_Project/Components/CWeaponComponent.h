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
	FORCEINLINE bool IsArmed() { return CurrentState == EStateType::Armed; }

private:
	class UCWeaponAsset* GetWeaponAsset(EWeaponType InType);

public:
	void SetKatanaMode();

private:
	void SetMode(EWeaponType InType);// 무기타입 바꾸기전 바꿀타입 명시하는 함수

	void ChangeWeaponType(EWeaponType InType); //무기 타입 바꾸는용도
	void ChangeState(EStateType InType); //상태 바꾸는용도

private:
	void Begin_Equip();
	void End_Equip();
	
private:
	UPROPERTY(EditDefaultsOnly, Category="Weapon Assets")
	TArray<class UCWeaponAsset*> WeaponAssets;

private:
	ACharacter* OwnerCharacter;
	
	EWeaponType CurrentWeaponType = EWeaponType::Max;

	EStateType CurrentState= EStateType::UnArmed;
};
