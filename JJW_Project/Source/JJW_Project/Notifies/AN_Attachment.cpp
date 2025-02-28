#include "AN_Attachment.h"
#include "GameFramework/Character.h"
#include "../Components/CWeaponComponent.h"
#include "../Weapons/CWeapon_Katana.h"

FString UAN_Attachment::GetNotifyName_Implementation() const
{
	return FString("AttachDetechWeapon");
}

void UAN_Attachment::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	Owner = Cast<ACharacter>(MeshComp->GetOwner());
	if (!Owner) return;

	UCWeaponComponent* WeaponComp = Owner->GetComponentByClass<UCWeaponComponent>();
	if (!WeaponComp) return;

	ACWeapon_Katana* Katana = Cast<ACWeapon_Katana>(WeaponComp->GetCurrentWeapon());
	if (!WeaponComp) return;

	UStaticMeshComponent* LeftHandMesh = Katana->GetLeftHandMesh();
	UStaticMeshComponent* RightHandMesh = Katana->GetRightHandMesh();

	if (bAttachToHand)
	{
		LeftHandMesh->AttachToComponent(MeshComp, FAttachmentTransformRules::SnapToTargetIncludingScale, Katana->GetLeftHandSocket());
		RightHandMesh->AttachToComponent(MeshComp, FAttachmentTransformRules::SnapToTargetIncludingScale, Katana->GetRightHandSocket());
	}
	else
	{
		LeftHandMesh->AttachToComponent(MeshComp, FAttachmentTransformRules::SnapToTargetIncludingScale, Katana->GetLeftHolsterSocket());
		RightHandMesh->AttachToComponent(MeshComp, FAttachmentTransformRules::SnapToTargetIncludingScale, Katana->GetRightHolsterSocket());
	}
}
