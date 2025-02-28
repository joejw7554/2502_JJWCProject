#include "CWeapon_Katana.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

ACWeapon_Katana::ACWeapon_Katana()
{

	RightHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHand_WeaponMesh");
	RightHandWeaponMesh->SetupAttachment(Root);
	LeftHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHand_WeaponMesh");
	LeftHandWeaponMesh->SetupAttachment(Root);

	SocketName_LeftHand = "HandL_Katana";
	SocketName_RightHand = "HandR_Katana";
	SocketName_HolsterLeftWeapon = "spine02_LeftWeapon";
	SocketName_HolsterRightWeapon = "spine02_RightWeapon";
}

void ACWeapon_Katana::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	RightHandWeaponMesh->SetCollisionProfileName("OverlapAllDynamic");
	LeftHandWeaponMesh->SetCollisionProfileName("OverlapAllDynamic");


	RightHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	LeftHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	RightHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	LeftHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}

void ACWeapon_Katana::BeginPlay()
{
	Super::BeginPlay();


	ACharacter* weaponOwner = Cast<ACharacter>(Owner);

	USkeletalMeshComponent* ownerMesh = weaponOwner->GetComponentByClass<USkeletalMeshComponent>();

	if (weaponOwner)
	{
		if (ownerMesh)
		{
			FAttachmentTransformRules transform(EAttachmentRule::SnapToTarget, true);

			RightHandWeaponMesh->AttachToComponent(ownerMesh, transform, SocketName_HolsterRightWeapon);
			LeftHandWeaponMesh->AttachToComponent(ownerMesh, transform, SocketName_HolsterLeftWeapon);
		}
	}


}
