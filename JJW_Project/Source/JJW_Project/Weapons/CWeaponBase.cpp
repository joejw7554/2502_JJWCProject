#include "CWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "CSkillComponent.h"

ACWeaponBase::ACWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	SkillComponent = CreateDefaultSubobject<UCSkillComponent>("SkillComponent");
}

void ACWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ACWeaponBase::Attack()
{
}


void ACWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

