#include "CWeaponComponent.h"

#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"

#include "CMovementComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "../Weapons/CWeaponAsset.h"

UCWeaponComponent::UCWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;

	MovementComp = OwnerCharacter->GetComponentByClass<UCMovementComponent>();


	for (UCWeaponAsset* asset : WeaponAssets)
	{
		if (asset)
		{
			SpawnWeapons(asset); // 스폰하고 무기 소켓에 붙여넣기 
		}
	}

	//활성화할 무기는 활성화모드	
	//비활성화 해야할건 비활성화하기
}

void UCWeaponComponent::SpawnWeapons(UCWeaponAsset* asset)
{
	if (!OwnerCharacter) return;

	FActorSpawnParameters params;
	params.Owner = OwnerCharacter;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACWeaponBase* weapon = GetWorld()->SpawnActor<ACWeaponBase>(asset->GetWeaponClass(), params);
	asset->SetWeapon(weapon);

	if (asset->GetWeaponType() == EWeaponType::Katana)
	{
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().LHolsterSocket);
		weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().RHolsterSocket);
		return;
	}
}

void UCWeaponComponent::AttachWeaponToSocket(EWeaponType InWeaponType)
{
	UCWeaponAsset* asset = GetWeaponAsset(InWeaponType);
	if (!asset) return;
	ACWeaponBase* weapon = asset->GetWeapon();
	if (!weapon) return;

	FName RHolsterSocket = asset->GetEquipmentData().RHolsterSocket;
	FName LHolsterSocket = asset->GetEquipmentData().LHolsterSocket;
	if (InWeaponType == EWeaponType::Katana)
	{
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, RHolsterSocket);
		weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, LHolsterSocket);
	}
}

void UCWeaponComponent::AttachWeaponToHand(EWeaponType InWeaponType)
{
	UCWeaponAsset* asset = GetWeaponAsset(InWeaponType);
	if (!asset) return;
	ACWeaponBase* weapon = asset->GetWeapon();
	if (!weapon) return;

	if (InWeaponType == EWeaponType::Katana)
	{
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().LHandSocket);
		weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().RHandSocket);
	}
}

UCWeaponAsset* UCWeaponComponent::GetWeaponAsset(EWeaponType InType)
{
	for (UCWeaponAsset* asset : WeaponAssets)
	{
		if (InType == asset->GetWeaponType())
			return asset;
	}
	return nullptr;
}

void UCWeaponComponent::SetKatanaMode()
{
	SetMode(EWeaponType::Katana);
}

void UCWeaponComponent::SetMode(EWeaponType InWeaponType)
{
	EWeaponType prevType = InWeaponType;

	if (IsUnArmed())
	{
		UE_LOG(LogTemp, Warning, TEXT("UnArmed 상태입니다. 선택한 무기 장착"));
		ChangeWeaponType(InWeaponType); 
		ActivateWeapon();
		Equip();
		return;
	}
	else if (CurrentWeaponType == InWeaponType)
	{
		UE_LOG(LogTemp, Warning, TEXT("현재 무기와 같은 무기입니다 장착해제."));
		DeActivateWeapon();
		return;
	}

	//현재무기와 같지도 않고 Unarmed가 아닐때의 경우:
	UE_LOG(LogTemp, Warning, TEXT("다른 무기를 선택하였습니다."));

	UCWeaponAsset* asset = GetWeaponAsset(InWeaponType);
	if (asset)
	{
		ChangeWeaponType(InWeaponType);
		ActivateWeapon();
		Equip();
	}
}

void UCWeaponComponent::ChangeWeaponType(EWeaponType InWeaponType)
{
	CurrentWeaponType = InWeaponType;
}

void UCWeaponComponent::ChangeState(EStateType InStateType)
{
	CurrentState = InStateType;
}

void UCWeaponComponent::ActivateWeapon()
{
	if (CurrentWeaponType == EWeaponType::Katana)
	{
		UMeshComponent* RightMesh = GetWeaponAsset(CurrentWeaponType)->GetWeapon()->GetRightMesh();
		UMeshComponent* LeftMesh = GetWeaponAsset(CurrentWeaponType)->GetWeapon()->GetLeftMesh();

		if (!RightMesh && !LeftMesh) return;

		RightMesh->SetVisibility(true);
		LeftMesh->SetVisibility(true);

	}
	ChangeState(EStateType::Armed);
}

void UCWeaponComponent::DeActivateWeapon()
{
	if (CurrentWeaponType == EWeaponType::Katana)
	{
		UMeshComponent* RightMesh = GetWeaponAsset(CurrentWeaponType)->GetWeapon()->GetRightMesh();
		UMeshComponent* LeftMesh = GetWeaponAsset(CurrentWeaponType)->GetWeapon()->GetLeftMesh();

		USkeletalMeshComponent* OwnerMesh = OwnerCharacter->GetMesh();
		FName RHolsterSocket = GetWeaponAsset(CurrentWeaponType)->GetEquipmentData().RHolsterSocket;
		FName LHolsterSocket = GetWeaponAsset(CurrentWeaponType)->GetEquipmentData().LHolsterSocket;

		if (!RightMesh && !LeftMesh) return;
		if (!OwnerMesh) return;

		RightMesh->SetVisibility(false);
		LeftMesh->SetVisibility(false);
		RightMesh->AttachToComponent(OwnerMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, RHolsterSocket);
		LeftMesh->AttachToComponent(OwnerMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, LHolsterSocket);
	}

	ChangeState(EStateType::UnArmed);
}


void UCWeaponComponent::Equip()
{
	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);

	if (!asset->GetEquipmentData().bCanMove)
		MovementComp->DisableMovment();

	if (!asset->GetEquipmentData().bCanRotate)
		MovementComp->DisableControlRotation();

	OwnerCharacter->PlayAnimMontage(GetWeaponAsset(CurrentWeaponType)->GetEquipmentData().EquipMontage);
}

void UCWeaponComponent::Begin_Equip()
{
	AttachWeaponToHand(CurrentWeaponType);
}

void UCWeaponComponent::End_Equip()
{
	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);

	if (!asset->GetEquipmentData().bCanMove)
		MovementComp->EnableMovement();

	if (!asset->GetEquipmentData().bCanRotate)
		MovementComp->EnableControlRotation();

	ChangeState(EStateType::Armed);
}


