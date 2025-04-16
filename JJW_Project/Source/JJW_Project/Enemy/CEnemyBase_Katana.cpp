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
	OnTakeAnyDamage.AddDynamic(this, &ACEnemyBase_Katana::OnEnemyTakeAnyDamage);
}

void ACEnemyBase_Katana::OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Super::OnEnemyTakeAnyDamage(DamagedActor, Damage, DamageType, InstigatedBy, DamageCauser);

	UE_LOG(LogTemp, Warning, TEXT("Damage Causer: %s"), *DamageCauser->GetActorLabel());
}


