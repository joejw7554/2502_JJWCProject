#include "CEnemyBase_Katana.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

#include "CMovementComponent_Enemy.h"
#include "Components/CWeaponComponent.h"
#include "CWeaponComponent_Enemy.h"
#include "CEnemyAnimInstance.h"
#include "CAIController.h"


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
	//OnTakeAnyDamage.AddDynamic(this, &ACEnemyBase_Katana::OnEnemyTakeAnyDamage);
}

void ACEnemyBase_Katana::OnEnemyTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Super::OnEnemyTakeAnyDamage(DamagedActor, Damage, DamageType, InstigatedBy, DamageCauser);


	ReactToHit(DamageCauser);
	SetTarget(DamageCauser);
}

void ACEnemyBase_Katana::ReactToHit(AActor* DamageCauser)
{
	// 공격 방향 계산
	FVector AttackDirection = (DamageCauser->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	FVector ForwardVector = GetActorForwardVector();
	FVector CrossProduct = FVector::CrossProduct(ForwardVector, AttackDirection);

	// 앞뒤 및 좌우 방향 결정
	float ForwardDot = FVector::DotProduct(ForwardVector, AttackDirection);
	float RightDot = CrossProduct.Z;

	// Hit 방향 판단
	EHitDireciton HitDirection = EHitDireciton::HitMax; // 기본값

	if (FMath::Abs(ForwardDot) > FMath::Abs(RightDot)) // 앞뒤 우선 판단
	{
		HitDirection = (ForwardDot > 0) ? EHitDireciton::HitFront : EHitDireciton::HitBack;
	}
	else // 좌우 판단
	{
		HitDirection = (RightDot > 0) ? EHitDireciton::HitRight : EHitDireciton::HitLeft;
	}

	// Hit Direction Map에서 몽타주 가져오기
	if (HitDirectionMap.Contains(HitDirection))
	{
		UAnimMontage* MontageToPlay = HitDirectionMap[HitDirection];
		if (MontageToPlay)
			PlayAnimMontage(MontageToPlay, HitReactionPlayRate);
	}

	ACAIController* controller = Cast<ACAIController>(GetController());
	if (controller && controller->GetBlackboardComponent())
	{
		controller->GetBlackboardComponent()->SetValueAsBool(TEXT("bIsTakingHit"), true);
	}
}

void ACEnemyBase_Katana::Dead()
{
	Super::Dead();

	if(OnEnemyDead.IsBound())
	OnEnemyDead.Broadcast();

	SetLifeSpan(3.f);
}

void ACEnemyBase_Katana::SetTarget(AActor* InDamageCauser)
{
	if (ACAIController* controller = Cast<ACAIController>(GetController()))
	{
		if (controller && controller->GetBlackboardComponent())
		{
			controller->GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), InDamageCauser);
		}
	}

}

