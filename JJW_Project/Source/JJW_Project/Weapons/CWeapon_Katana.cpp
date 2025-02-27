#include "CWeapon_Katana.h"
#include "GameFramework/Character.h"

ACWeapon_Katana::ACWeapon_Katana()
{
	LeftWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("LeftHand_WeaponMesh");
	LeftWeaponMesh->SetupAttachment(Root);



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
