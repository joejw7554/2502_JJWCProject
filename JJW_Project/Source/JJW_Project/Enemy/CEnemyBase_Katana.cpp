#include "CEnemyBase_Katana.h"
#include "CMovementComponent_Enemy.h"
#include "Components/CWeaponComponent.h"
#include "CWeaponComponent_Enemy.h"
#include "CEnemyAnimInstance.h"
#include "Components/SkeletalMeshComponent.h"

ACEnemyBase_Katana::ACEnemyBase_Katana()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponComponent = CreateDefaultSubobject<UCWeaponComponent_Enemy>(TEXT("WeaponComponent"));
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

	FVector attackDirection = DamageCauser->GetActorLocation() - GetActorLocation();

	FVector forwardVector = GetActorForwardVector();
	FVector rightVector = GetActorRightVector();

	float forwardDot = FVector::DotProduct(forwardVector, attackDirection);
	FVector crossProduct = FVector::CrossProduct(forwardVector, attackDirection);
	float rightDot = crossProduct.Z;

	float X = rightDot;
	float Y = forwardDot;

	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (!animInstance) return;

	UCEnemyAnimInstance* enemyAnimIntance= Cast<UCEnemyAnimInstance>(animInstance);
	if (!enemyAnimIntance) return;

	enemyAnimIntance->SetHitDirectionX(X);
	enemyAnimIntance->SetHitDirectionY(Y);

	//REVIEW THIS PART
}


