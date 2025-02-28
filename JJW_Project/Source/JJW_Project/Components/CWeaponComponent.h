#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "CWeaponComponent.generated.h"


//Delegate사용해서 웨폰에 명령을 내릴까?
UENUM()
enum class EWeaponType : uint8
{
	None, Katana = 0
};


UCLASS()
class JJW_PROJECT_API UCWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCWeaponComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	ACWeaponBase* GetCurrentWeapon();
	void SetKatanaMode();



protected:
	virtual void BeginPlay() override;

	void SpawnWeapons();


private:
	void EquipWeapon(EWeaponType InPrevType, EWeaponType InNewType);


protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
	TArray<TSubclassOf<class ACWeaponBase>> WeaponClassToSpawn;

	UPROPERTY(VisibleAnywhere, Category = "Weapons")
	TArray<class ACWeaponBase*> ActiveWeapons;

private:
	UPROPERTY(VisibleAnywhere, Category = "Value Debug")
	EWeaponType CurrentWeaponType = EWeaponType::None;

	UPROPERTY(VisibleAnywhere, Category = "Value Debug")
	ACWeaponBase* CurrentWeapon;

	UPROPERTY(VisibleAnywhere, Category = "Value Debug")
	ACharacter* Owner;
};
