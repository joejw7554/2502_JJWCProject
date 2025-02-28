#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CWeaponBase.generated.h"

UCLASS(Abstract)
class JJW_PROJECT_API ACWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	ACWeaponBase();

protected:
	virtual void BeginPlay() override;

	virtual void Attack(); //자식에서 재정의해서 쓰는용도


public:
	virtual void Tick(float DeltaTime) override;

	void Equip();

	virtual void ShowWeapon() {}
	virtual void HideWeapon() {}

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	class UCSkillComponent* SkillComponent;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	FName SocketName_RightHand;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	FName SocketName_HolsterRightWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	class UAnimMontage* EquipMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	float EquipMontage_PlayRate = 1.25f;

};
