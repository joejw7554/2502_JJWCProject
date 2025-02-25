#include "CPlayerAnim.h"
#include "CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"



void UCPlayerAnim::NativeInitializeAnimation()
{
	Owner = Cast<ACPlayer>(TryGetPawnOwner());

	if (!Owner) return;

	Movement = Owner->GetCharacterMovement();
}

void UCPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Movement)
		Speed = Movement->Velocity.Size2D();
}
