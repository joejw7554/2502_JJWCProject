#include "CWeapon_Katana.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "CWeaponStructure.h"

ACWeapon_Katana::ACWeapon_Katana()
{

	RightHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHand_WeaponMesh");
	RightHandWeaponMesh->SetupAttachment(Root);
	LeftHandWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHand_WeaponMesh");
	LeftHandWeaponMesh->SetupAttachment(Root);

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

void ACWeapon_Katana::InitializeWeapon(const FEquipmentData& InData)
{
	if (!OwnerCharacter) return;

	RightHandWeaponMesh->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, InData.RHolsterSocket);
	LeftHandWeaponMesh->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, InData.LHolsterSocket);
}

void ACWeapon_Katana::BeginPlay()
{
	Super::BeginPlay();
}
