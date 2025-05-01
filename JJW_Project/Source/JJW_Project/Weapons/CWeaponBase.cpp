#include "CWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

#include "CSkillStructure.h"

#include "../Components/CSkill_Q.h"
#include "../Components/CSkill_W.h"
#include "../Components/CSkill_E.h"
#include "../Components/CSkill_R.h"
#include "../Components/CSkill_BasicCombo.h"
#include "../Components/CWeaponComponent.h"
#include "Stats/CStatComponent.h"
#include "Player/CPlayer.h"
#include "Player/CPlayerState.h"
#include "Enemy/CEnemyBase.h"


ACWeaponBase::ACWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	RightHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHand_WeaponMesh");
	RightHandWeaponMesh->SetupAttachment(Root);
	RightHandWeaponMesh->SetCollisionProfileName("NoCollision");

	LeftHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHand_WeaponMesh");
	LeftHandWeaponMesh->SetupAttachment(Root);
	LeftHandWeaponMesh->SetCollisionProfileName("NoCollision");

	//SkillComponents
	{
		BasicCombo = CreateDefaultSubobject<UCSkill_BasicCombo>("BasicCombo");
		Skill_Q = CreateDefaultSubobject<UCSkill_Q>("Skill_Q");
		Skill_W = CreateDefaultSubobject<UCSkill_W>("Skill_W");
		Skill_E = CreateDefaultSubobject<UCSkill_E>("Skill_E");
		Skill_R = CreateDefaultSubobject<UCSkill_R>("Skill_R");
	}

}

void ACWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner()->IsA<ACPlayer>())
	{
		PlayerCharacter = Cast<ACPlayer>(GetOwner());
		bIsOwnerPlayer = true;
	}
	else if (GetOwner()->IsA<ACEnemyBase>())
	{
		EnemyCharacter = Cast<ACEnemyBase>(GetOwner());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Owner is not Player or Enemy"));
		return;
	}

	if (RightHandWeaponMesh)
	{
		RightHandWeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponBeginOverlap);
		RightHandWeaponMesh->OnComponentEndOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponEndOverlap);
	}

	if (LeftHandWeaponMesh)
	{
		LeftHandWeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponBeginOverlap);
		LeftHandWeaponMesh->OnComponentEndOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponEndOverlap);
	}


	DamagedActors.Reserve(10);

	ACEnemyBase* ownerEnemy = Cast<ACEnemyBase>(GetOwner());
	if (!ownerEnemy) return;

	ownerEnemy->OnEnemyDead.AddDynamic(this, &ACWeaponBase::OnEnenmyDead);
}


//void ACWeaponBase::OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//	if (OtherActor->ActorHasTag("Enemy") && !DamagedActors.Contains(OtherActor))
//	{
//		if (!PlayerCharacter) return;
//		ACPlayerState* playerState = PlayerCharacter->GetPlayerState();
//		if (!playerState) return;
//
//		UCStatComponent* statCompo = playerState->GetStatComponent();
//		if (!statCompo) return;
//
//
//		float strength = statCompo->GetStatValue(FName("Strength"));
//		float finalDamage = Damage + strength;
//		UE_LOG(LogTemp, Warning, TEXT("Total Damage : %f"), finalDamage);
//
//		if (!PlayerCharacter) return;
//		if (!PlayerCharacter->GetController()) return;
//
//		UGameplayStatics::ApplyDamage(OtherActor, finalDamage, PlayerCharacter->GetController(), PlayerCharacter, nullptr);
//		DamagedActors.AddUnique(OtherActor);
//	}
//
//}

void ACWeaponBase::OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!GetOwner() || DamagedActors.Contains(OtherActor) || OtherActor == GetOwner()) return;

	bool bIsEnemyTarget = OtherActor->ActorHasTag("Enemy");
	bool bIsPlayerTarget = OtherActor->ActorHasTag("Player");

	if (bIsOwnerPlayer && bIsEnemyTarget)
	{
		float FinalDamage = CalculateDamageForPlayer();
		ApplyDamage(OtherActor, FinalDamage, PlayerCharacter);
	}
	else if (!bIsOwnerPlayer && bIsPlayerTarget)
	{
		ApplyDamage(OtherActor, Damage, EnemyCharacter);
	}


	if (Cast<IStatus>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("This is a player Possess IStatus"));
	}


	


}

float ACWeaponBase::CalculateDamageForPlayer() const
{
	float FinalDamage = Damage;

	if (PlayerCharacter)
	{
		ACPlayerState* PlayerState = PlayerCharacter->GetPlayerState();
		if (PlayerState)
		{
			UCStatComponent* StatComp = PlayerState->GetStatComponent();
			if (StatComp)
			{
				float Strength = StatComp->GetStatValue(FName("Strength"));
				FinalDamage += Strength;
			}
		}
	}


	return FinalDamage;
}

void ACWeaponBase::ApplyDamage(AActor* TargetActor, float DamageAmount, ACharacter* DamageCauser) 
{
	if (TargetActor && DamageCauser)
	{
		/*UE_LOG(LogTemp, Warning, TEXT("DamagedTarget: %s"), *TargetActor->GetActorLabel());
		UE_LOG(LogTemp, Warning, TEXT("Damage Amount : %f"), DamageAmount);*/
		UGameplayStatics::ApplyDamage(TargetActor, DamageAmount, DamageCauser->GetController(), DamageCauser, nullptr);
		DamagedActors.AddUnique(TargetActor);
	}
}

void ACWeaponBase::OnWeaponEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	DamagedActors.Empty();
}

void ACWeaponBase::OnEnenmyDead()
{
	Destroy();
}
