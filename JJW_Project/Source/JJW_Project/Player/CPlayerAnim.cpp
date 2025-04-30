#include "CPlayerAnim.h"
#include "CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CWeaponComponent.h"



void UCPlayerAnim::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (!OwnerCharacter) return;

	Movement = OwnerCharacter->GetCharacterMovement();
}

void UCPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Movement)
		Speed = Movement->Velocity.Size2D();
}

void UCPlayerAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!player) return;


}

