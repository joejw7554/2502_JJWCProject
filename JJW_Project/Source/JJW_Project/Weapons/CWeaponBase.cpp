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

	DamagedActors.Reserve(5);
}


void ACWeaponBase::OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//여기 수정사항 있을꺼 같음 
	if (OtherActor->ActorHasTag("Enemy") && !DamagedActors.Contains(OtherActor))
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, nullptr, this, nullptr);
		DamagedActors.AddUnique(OtherActor);
	}
}

void ACWeaponBase::OnWeaponEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for (AActor* actor : DamagedActors)
	{
		UE_LOG(LogTemp, Warning, TEXT("Damaged Actor : %s"), *actor->GetName());
	}

	DamagedActors.Empty();
}
