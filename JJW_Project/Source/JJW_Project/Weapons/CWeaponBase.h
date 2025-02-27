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


protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	class UCSkillComponent* SkillComponent;

	UPROPERTY(VisibleAnywhere)
	FName SocketName_RightHand;

	UPROPERTY(VisibleAnywhere)
	FName SocketName_LeftHand;

	UPROPERTY(VisibleAnywhere)
	FName SocketName_WeaponHolster;
};
