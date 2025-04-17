#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CEnemyAnimInstance.generated.h"

UCLASS()
class JJW_PROJECT_API UCEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

private:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY()
	class ACEnemyBase* EnemyOwner;

	UPROPERTY()
	class UCharacterMovementComponent* EnemyMovementComponent;
};
