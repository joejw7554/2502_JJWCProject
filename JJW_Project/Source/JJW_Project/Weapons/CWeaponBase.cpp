#include "CWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"


ACWeaponBase::ACWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	RightHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHand_WeaponMesh");
	RightHandWeaponMesh->SetupAttachment(Root);
	RightHandWeaponMesh->SetCollisionProfileName("NoCollision"); //다시 NoCollision으로 바꾸기

	LeftHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHand_WeaponMesh");
	LeftHandWeaponMesh->SetupAttachment(Root);
	LeftHandWeaponMesh->SetCollisionProfileName("NoCollision"); //다시 NoCollision으로 바꾸기
}

void ACWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());


	if (RightHandWeaponMesh)
	{
		RightHandWeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponBeginOverlap);
	}

	if (LeftHandWeaponMesh)
	{
		LeftHandWeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &ACWeaponBase::OnWeaponBeginOverlap);
	}
}

void ACWeaponBase::OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Weapon Overlap"));

	if (OtherActor->ActorHasTag("Enemy"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Enemy"));

		if (OverlappedComponent == RightHandWeaponMesh)
		{
			UE_LOG(LogTemp, Warning, TEXT("Right Hand Weapon hit Enemy"));
		}
		else if (OverlappedComponent == LeftHandWeaponMesh)
		{
			UE_LOG(LogTemp, Warning, TEXT("Left Hand Weapon hit Enemy"));
		}
	}
}




