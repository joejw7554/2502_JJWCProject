#include "CWeapon_Katana.h"
#include "GameFramework/Character.h"

ACWeapon_Katana::ACWeapon_Katana()
{
	ExtraMesh = CreateDefaultSubobject<USkeletalMeshComponent>("LeftHand_WeaponMesh");
	ExtraMesh->SetupAttachment(Root);
	/*SocketName_LeftHand=
	SocketName_RightHand=*/
}

void ACWeapon_Katana::BeginPlay()
{
	Super::BeginPlay();


	ACharacter* weaponOwner = Cast<ACharacter>(Owner);

	USkeletalMeshComponent* weaponOwnerMesh = weaponOwner->GetComponentByClass<USkeletalMeshComponent>();

	if (weaponOwner)
	{
		if (weaponOwnerMesh)
		{
			FAttachmentTransformRules transform(EAttachmentRule::SnapToTarget, true);
			//ExtraMesh->AttachToComponent(ExtraMesh, transform, )
			//칼 뺏을때 칼집만 남게할수있는 방법이 없을까?
		}
	}


}
