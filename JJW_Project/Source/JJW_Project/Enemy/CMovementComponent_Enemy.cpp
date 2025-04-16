#include "Enemy/CMovementComponent_Enemy.h"

void UCMovementComponent_Enemy::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;


}
