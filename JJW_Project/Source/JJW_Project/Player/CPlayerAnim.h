#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPlayerAnim.generated.h"

UCLASS()
class JJW_PROJECT_API UCPlayerAnim : public UAnimInstance
{
public:
	virtual void NativeBeginPlay() override;

	GENERATED_BODY()
protected:
	class ACharacter* Owner;

	class UMovementComponent* MoveComp;

};
