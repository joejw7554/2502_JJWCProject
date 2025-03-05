#include "CWeaponComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "../Weapons/CWeaponAsset.h"
#include "GameFramework/Character.h"

UCWeaponComponent::UCWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;

	for (UCWeaponAsset* asset : WeaponAssets)
	{
		//asset->GetEquipmentData().LHandSocket
	}

	//TODO: 기본으로 무기 소켓에 붙여넣기 
	//활성화할 무기는 활성화모드	
	//비활성화 해야할건 비활성화하기
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

void UCWeaponComponent::SetMode(EWeaponType InType)
{
	if (CurrentWeaponType == InType)
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
	UCWeaponAsset* asset = GetWeaponAsset(InType);
	if (asset)
	{
		ChangeWeaponType(InType);
		ChangeState(EStateType::Armed);
	}
}

void UCWeaponComponent::ChangeWeaponType(EWeaponType InType)
{
	EWeaponType prevType = CurrentWeaponType;
	CurrentWeaponType = InType;
}

void UCWeaponComponent::ChangeState(EStateType InType)
{
	CurrentState = InType;
}

void UCWeaponComponent::Begin_Equip()
{
}

void UCWeaponComponent::End_Equip()
{
}


