#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPlayerAnim.generated.h"

UCLASS()
class JJW_PROJECT_API UCPlayerAnim : public UAnimInstance
{

	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


protected:
	UPROPERTY(VisibleAnywhere, Category="Player Property", BlueprintReadOnly)
	float Speed;

private:
	class ACharacter* Owner;

	class UMovementComponent* Movement;

};
