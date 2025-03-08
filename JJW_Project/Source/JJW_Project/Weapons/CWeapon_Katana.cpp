#include "CWeapon_Katana.h"

void ACWeapon_Katana::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	RightHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	LeftHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	RightHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	LeftHandWeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}

void ACWeapon_Katana::BeginPlay()
{
	Super::BeginPlay();

}
