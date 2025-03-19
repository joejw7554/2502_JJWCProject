#include "Enemy/CEnemyBase.h"

#include "Components/CapsuleComponent.h"

#include "Framework/CGameMode.h"
#include "Item/CItemBase.h"
#include "Components/CItemFactoryComponent.h"
#include "Components/SkeletalMeshComponent.h"
ACEnemyBase::ACEnemyBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add("Enemy");

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
}

void ACEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	OnTakeAnyDamage.AddDynamic(this, &ACEnemyBase::OnEnemyTakeAnyDamage);
}

void ACEnemyBase::DropItem()
{
	ACGameMode* gameMode = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
	if (!gameMode) return;

	gameMode->GetItemFactory()->CreateDropItem(EnemyType, GetActorLocation());
}

void ACEnemyBase::Dead()
{
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	Destroy();
}

void ACEnemyBase::OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);

	if (IsDead())
	{
		UE_LOG(LogTemp, Warning, TEXT("CurrentHealth: %f"), CurrentHealth);
		DropItem();
		Dead();
	}
}
