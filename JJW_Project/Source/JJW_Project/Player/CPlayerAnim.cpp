#include "CPlayerAnim.h"
#include "CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CWeaponComponent.h"



void UCPlayerAnim::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());

	if (!OwnerCharacter) return;

	Movement = OwnerCharacter->GetCharacterMovement();

	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!player) return;

	player->GetWeaponComponent()->OnWeaponTypeChanged.AddDynamic(this, &UCPlayerAnim::OnWeaponTypeChanged);
}

void UCPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Movement)
		Speed = Movement->Velocity.Size2D();
}

void UCPlayerAnim::OnWeaponTypeChanged(EWeaponType InPrevType, EWeaponType InNewType)
{
}
