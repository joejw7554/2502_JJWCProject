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
}

void ACWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* ownerCharacter = Cast<ACharacter>(Owner);
}


void ACWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACWeaponBase::Equip()
{
	ACharacter* ownerCharacter= Cast<ACharacter>(Owner);
}

