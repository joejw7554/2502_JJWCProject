#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item/CItemStructure.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CEnemyBase.generated.h"

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	Normal, MAX
};

UCLASS()
class JJW_PROJECT_API ACEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACEnemyBase();

	void SetWalkMode() { GetCharacterMovement()->MaxWalkSpeed = RunSpeed; }
	void SetRunMode() { GetCharacterMovement()->MaxWalkSpeed = WalkSpeed; }

protected:
	virtual void BeginPlay() override;

protected:
	virtual void DropItem();
	virtual void Dead();

	bool IsDead() { return CurrentHealth <= 0 ? true : false; }

	UFUNCTION()
	void OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

private:
	UPROPERTY(EditDefaultsOnly)
	EEnemyType EnemyType = EEnemyType::Normal;

private:
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* WeaponLCollision;

	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* WeaponRCollision;

	UPROPERTY(EditDefaultsOnly)
	float WalkSpeed = 200.f;

	UPROPERTY(EditDefaultsOnly)
	float RunSpeed = 400.f;

		UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;

	UPROPERTY()
	float CurrentHealth = MaxHealth;

	UPROPERTY(EditDefaultsOnly)
	float EXPValue = 10.f;

	UPROPERTY(VisibleAnywhere)
	class UCWeaponComponent* WeaponComponent;
};
