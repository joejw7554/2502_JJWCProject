#include "Enemy/CEnemyAnimInstance.h"
#include "CEnemyBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();


	AActor* owner = GetOwningActor();
	if (!owner)return;

	EnemyOwner = Cast<ACEnemyBase>(owner);
	if (!EnemyOwner) return;

	EnemyMovementComponent = EnemyOwner->GetCharacterMovement();
}

void UCEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!EnemyMovementComponent) return;
	Speed = EnemyMovementComponent->Velocity.Size();
}
