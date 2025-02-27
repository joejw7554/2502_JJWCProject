#include "CWeapon_Katana.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

ACWeapon_Katana::ACWeapon_Katana()
{
	RightHandMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHand_WeaponMesh");
	RightHandMesh->SetupAttachment(Root);

	LeftHandMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHand_WeaponMesh");
	LeftHandMesh->SetupAttachment(Root);
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

			/*RightWeaponMesh->AttachToComponent(ownerMesh, transform, "");
			LeftWeaponMesh->AttachToComponent(ownerMesh, transform, "");*/
		}
	}


}
