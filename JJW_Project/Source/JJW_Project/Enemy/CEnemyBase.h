#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item/CItemStructure.h"
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
	//virtual void Tick(float DeltaTime) override;

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
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;

	UPROPERTY()
	float CurrentHealth = MaxHealth;

	UPROPERTY(EditDefaultsOnly)
	float EXPValue = 10.f;

	UPROPERTY(VisibleAnywhere)
	class UCWeaponComponent* WeaponComponent;
};
