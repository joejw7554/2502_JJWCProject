#include "Enemy/CEnemyBase.h"

#include "Components/CapsuleComponent.h"

#include "Framework/CGameMode.h"
#include "Item/CItemBase.h"
#include "Components/CItemFactoryComponent.h"
#include "Components/SkeletalMeshComponent.h"


#include "Player/CPlayerState.h"
#include "Stats/CStatComponent.h"
#include "Components/CWeaponComponent.h"
#include "CAIController.h"

ACEnemyBase::ACEnemyBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add("Enemy");

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	WeaponComponent = CreateDefaultSubobject<UCWeaponComponent>(TEXT("WeaponComponent"));

	ConstructorHelpers::FClassFinder<ACAIController> AI_controller(L"/Script/Engine.Blueprint'/Game/Blueprints/Enemy/BP_CAIController.BP_CAIController_C'");
	if (AI_controller.Succeeded())
	{
		AIControllerClass = AI_controller.Class;
	}
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

	float radius = GetCapsuleComponent()->GetUnscaledCapsuleRadius();
	FVector capsuleLocation = GetCapsuleComponent()->GetComponentLocation();
	float capsuleRadius = GetCapsuleComponent()->GetUnscaledCapsuleRadius();

	gameMode->GetItemFactory()->CreateDropItem(EnemyType, capsuleLocation, capsuleRadius);
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
		DropItem();
		if (InstigatedBy)
		{
			ACPlayerState* playerState =(InstigatedBy->GetPlayerState<ACPlayerState>());
			if (!playerState) return;

			playerState->GetStatComponent()->AddPlayerEXP(EXPValue);
		}
		Dead();
	}
}
