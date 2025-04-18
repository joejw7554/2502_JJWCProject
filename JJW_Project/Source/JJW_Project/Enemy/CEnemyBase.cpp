#include "Enemy/CEnemyBase.h"


#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

#include "Item/CItemBase.h"
#include "Framework/CGameMode.h"
#include "Player/CPlayerState.h"
#include "Stats/CStatComponent.h"
#include "Components/CItemFactoryComponent.h"
#include "CAIController.h"
#include "Components/CDamageUIComponent.h"
#include "UI/CUI_Damage.h"

ACEnemyBase::ACEnemyBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add("Enemy");

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	ConstructorHelpers::FClassFinder<ACAIController> AI_controller(L"/Script/Engine.Blueprint'/Game/Blueprints/Enemy/AI/BP_CAIController.BP_CAIController_C'");
	if (AI_controller.Succeeded())
	{
		AIControllerClass = AI_controller.Class;
	}


	DamageUIComponent = CreateDefaultSubobject<UCDamageUIComponent>(TEXT("DamageUIComponent"));
	DamageUIComponent->SetupAttachment(RootComponent);
	DamageUIComponent->SetWidgetSpace(EWidgetSpace::Screen);
	DamageUIComponent->SetRelativeLocation(FVector(0, 0, 80.f));
	SetWalkMode();
}

void ACEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	OnTakeAnyDamage.AddDynamic(this, &ACEnemyBase::OnEnemyTakeAnyDamage);

	DamageUI = Cast<UCUI_Damage>(DamageUIComponent->GetUserWidgetObject());
	if (!DamageUI) return;

	OnEnemyDamaged.AddDynamic(DamageUI, &UCUI_Damage::PlayDamageAnimation);
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
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//Destroy();
}

void ACEnemyBase::OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
	OnEnemyDamaged.Broadcast(Damage);

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
