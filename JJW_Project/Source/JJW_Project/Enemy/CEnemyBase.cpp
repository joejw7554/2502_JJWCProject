#include "Enemy/CEnemyBase.h"

ACEnemyBase::ACEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

