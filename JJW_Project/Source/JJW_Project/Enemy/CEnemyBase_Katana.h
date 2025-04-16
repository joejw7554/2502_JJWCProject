#pragma once

#include "CoreMinimal.h"
#include "Enemy/CEnemyBase.h"
#include "CEnemyBase_Katana.generated.h"

UENUM(BlueprintType)
enum class EHitDireciton :uint8
{
	HitFront,
	HitBack,
	HitLeft,
	HitRight,
	HitMax
};

UCLASS()
class JJW_PROJECT_API ACEnemyBase_Katana : public ACEnemyBase
{
	GENERATED_BODY()

public:
	ACEnemyBase_Katana();
	FORCEINLINE class UCWeaponComponent* GetWeaponComponent() { return WeaponComponent; }
	FORCEINLINE class UCMovementComponent_Enemy* GetMovementComponent() { return MovementComponent; }

protected:
	virtual void BeginPlay() override;

	virtual void OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) override;

private:
	UPROPERTY(VisibleAnywhere)
	class UCWeaponComponent* WeaponComponent;

	UPROPERTY(VisibleAnywhere)
	class UCMovementComponent_Enemy* MovementComponent;

	UPROPERTY(EditDefaultsOnly)
	TMap<EHitDireciton, UAnimMontage*> HitMontages;

	UPROPERTY(EditDefaultsOnly)
	float HitMontagePlayRate = 1.0f;
};
