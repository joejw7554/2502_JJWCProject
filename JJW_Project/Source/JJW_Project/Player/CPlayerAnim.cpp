#include "CPlayerAnim.h"
#include "CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCPlayerAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Owner = Cast<ACPlayer>(TryGetPawnOwner());

}
