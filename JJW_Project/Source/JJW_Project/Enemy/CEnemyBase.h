#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item/CItemStructure.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CEnemyBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEnemyDead);

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	Normal, MAX
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyDamaged, float, Damage);

UCLASS()
class JJW_PROJECT_API ACEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	FEnemyDamaged OnEnemyDamaged;

	FEnemyDead OnEnemyDead;

public:
	ACEnemyBase();

	void SetWalkMode() { GetCharacterMovement()->MaxWalkSpeed = RunSpeed; }
	void SetRunMode() { GetCharacterMovement()->MaxWalkSpeed = WalkSpeed; }
	class UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }

protected:
	virtual void BeginPlay() override;
	virtual void SpawnWeapon() {}

protected:
	virtual void DropItem();
	virtual void Dead();

	bool IsDead() { return CurrentHealth <= 0 ? true : false; }

	UFUNCTION()
	virtual void OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

protected:
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BehaviorTree;

	UPROPERTY()
	class ACWeaponBase* Weapon;


private:
	UPROPERTY(EditDefaultsOnly)
	EEnemyType EnemyType = EEnemyType::Normal;

private:
	UPROPERTY(EditDefaultsOnly)
	float WalkSpeed = 200.f;

	UPROPERTY(EditDefaultsOnly)
	float RunSpeed = 400.f;

		UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;

	UPROPERTY()
	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly)
	float EXPValue = 10.f;

	UPROPERTY(VisibleAnywhere)
	class UCDamageUIComponent* DamageUIComponent;

	UPROPERTY()
	class UCUI_Damage* DamageUI;


};
