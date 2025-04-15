#include "CEnemyBase_Katana.h"
#include "CMovementComponent_Enemy.h"
#include "Components/CWeaponComponent.h"

ACEnemyBase_Katana::ACEnemyBase_Katana()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponComponent = CreateDefaultSubobject<UCWeaponComponent>(TEXT("WeaponComponent"));
	MovementComponent = CreateDefaultSubobject<UCMovementComponent_Enemy>(TEXT("MovementComponent"));

}

void ACEnemyBase_Katana::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->HideBoneByName(TEXT("weapon_l"), EPhysBodyOp::PBO_None);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
}


