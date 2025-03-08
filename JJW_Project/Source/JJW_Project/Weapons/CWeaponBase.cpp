#include "CWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "CSkillComponent.h"


ACWeaponBase::ACWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	RightHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHand_WeaponMesh");
	RightHandWeaponMesh->SetupAttachment(Root);

	LeftHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHand_WeaponMesh");
	LeftHandWeaponMesh->SetupAttachment(Root);

	SkillComponent = CreateDefaultSubobject<UCSkillComponent>("SkillComponent");
}

void ACWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());


	//if (RightHandWeaponMesh)
	//{
	//	RightHandWeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponBeginOverlap);
	//}

	//if (LeftHandWeaponMesh)
	//{
	//	LeftHandWeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponBeginOverlap);
	//}
}

//void ACWeaponBase::OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor->ActorHasTag("Enemy"))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Hit Enemy"));
//	}
//
//}




