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
}

void ACWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
}




