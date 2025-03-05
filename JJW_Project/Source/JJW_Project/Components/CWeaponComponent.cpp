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
	//이걸 여기서 구현해 말아?
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

	if (CurrentWeaponType == InWeaponType)
	{
		//현재 무기 장착해제
		ChangeState(EStateType::UnArmed);
	}
	else if (IsUnArmed())
	{
		//선택된 무기 모드 변경
		//선택된 무기 장착
		ChangeState(EStateType::Armed);
	}

	//현재무기와 같지도 않고 Unarmed가 아닐때의 경우:

		//현재무기 비활성화
		//선택무기 활성화
	UCWeaponAsset* asset = GetWeaponAsset(InWeaponType);
	if (asset)
	{
		ChangeWeaponType(InWeaponType);
		ChangeState(EStateType::Armed);
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


void UCWeaponComponent::EquipSetup()
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
}

void UCWeaponComponent::End_Equip()
{
}


