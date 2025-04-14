#include "CEnemyBase_Katana.h"
#include "Weapons/CWeapon_Katana.h"
#include "Weapons/CWeaponAsset.h"

ACEnemyBase_Katana::ACEnemyBase_Katana()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponComponent = CreateDefaultSubobject<UCWeaponComponent>(TEXT("WeaponComponent"));
	MovementComponent = CreateDefaultSubobject<UCMovementComponent>(TEXT("MovementComponent"));
}

void ACEnemyBase_Katana::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->HideBoneByName(TEXT("weapon_l"), EPhysBodyOp::PBO_None);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);

	//SpawnWeapon();
}

void ACEnemyBase_Katana::SpawnWeapon()
{
	if (!WeaponData) return;

	FActorSpawnParameters params;
	params.Owner = this;
	params.Instigator = Cast<APawn>(GetController());
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	Weapon = GetWorld()->SpawnActor<ACWeapon_Katana>(WeaponData->GetWeaponClass(), FVector::ZeroVector, FRotator::ZeroRotator, params);
	if (!Weapon)return;

	WeaponData->SetWeapon(Weapon);
	Weapon->GetRightMesh()->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponData->GetEquipmentData().RHandSocket);
	Weapon->GetLeftMesh()->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponData->GetEquipmentData().LHandSocket);
}
