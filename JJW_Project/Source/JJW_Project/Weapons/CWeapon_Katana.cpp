#include "CWeapon_Katana.h"

ACWeapon_Katana::ACWeapon_Katana()
{
	ExtraMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ExtraLeftHandMesh");
	ExtraMesh->SetupAttachment(Root);
	/*SocketName_LeftHand=
	SocketName_RightHand=*/
}

void ACWeapon_Katana::BeginPlay()
{
	Super::BeginPlay();

	//Owner가 존재한다!

}
