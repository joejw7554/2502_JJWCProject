#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CEnemyAnimInstance.generated.h"

UCLASS()
class JJW_PROJECT_API UCEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FORCEINLINE void EnemyDeadActivated() { bIsDead = true; }

	UFUNCTION()
	FORCEINLINE void EnemyDeadDeactivated() { bIsDead = false; } //Just Incase if it's necessary

private:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeBeginPlay() override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY()
	class ACEnemyBase* EnemyOwner;

	UPROPERTY()
	class UCharacterMovementComponent* EnemyMovementComponent;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDead;
};
