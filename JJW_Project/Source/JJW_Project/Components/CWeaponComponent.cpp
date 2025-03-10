#include "CWeaponComponent.h"

#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"

#include "CMovementComponent.h"
#include "../Weapons/CWeaponBase.h"
#include "../Weapons/CWeaponAsset.h"

#include "CSkill_Q.h"
#include "CSkill_W.h"
#include "CSkill_E.h"
#include "CSkill_R.h"
#include "CSkill_BasicCombo.h"

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
	if (!MovementComp) return;

	for (UCWeaponAsset* asset : WeaponAssets)
	{
		if (asset)
			SpawnWeapons(asset); // 스폰하고 무기 소켓에 붙여넣기 
	}
}

void UCWeaponComponent::SpawnWeapons(UCWeaponAsset* asset)
{
	if (!OwnerCharacter) return;

	FActorSpawnParameters params;
	params.Owner = OwnerCharacter;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACWeaponBase* weapon = GetWorld()->SpawnActor<ACWeaponBase>(asset->GetWeaponClass(), params);
	if (!weapon) return; 

	asset->SetWeapon(weapon);
	asset->GetWeapon()->GetBasicCombo()->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::BasicCombo);
	asset->GetWeapon()->GetSkill_Q()->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::Q);
	asset->GetWeapon()->GetSkill_W()->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::W);
	asset->GetWeapon()->GetSkill_E()->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::E);
	asset->GetWeapon()->GetSkill_R()->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::R);

	weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().RHolsterSocket);

	if (asset->GetWeaponType() == EWeaponType::Katana)
	{
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().LHolsterSocket);
	}	

	DeActivateWeapon(asset->GetWeaponType());
}

void UCWeaponComponent::AttachWeaponToSocket(EWeaponType WeaponType)
{
	UCWeaponAsset* asset = GetWeaponAsset(WeaponType);
	if (!asset) return;
	ACWeaponBase* weapon = asset->GetWeapon();
	if (!weapon) return;

	FAttachmentTransformRules transformRules = FAttachmentTransformRules::SnapToTargetIncludingScale;

	if (WeaponType == EWeaponType::Katana)
	{
		FName LHolsterSocket = asset->GetEquipmentData().LHolsterSocket;
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), transformRules, LHolsterSocket);
	}

	FName RHolsterSocket = asset->GetEquipmentData().RHolsterSocket;
	weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), transformRules, RHolsterSocket);

}

void UCWeaponComponent::AttachWeaponToHand(EWeaponType WeaponType)
{
	UCWeaponAsset* asset = GetWeaponAsset(WeaponType);
	if (!asset) return;
	ACWeaponBase* weapon = asset->GetWeapon();
	if (!weapon) return;

	FAttachmentTransformRules transformRules = FAttachmentTransformRules::SnapToTargetIncludingScale;

	if (WeaponType == EWeaponType::Katana)
	{
		FName LHandSocket = asset->GetEquipmentData().LHandSocket;
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), transformRules, LHandSocket);
	}

	USkeletalMeshComponent* OwnerMesh = OwnerCharacter->GetMesh();
	FName RHandSocket = asset->GetEquipmentData().RHandSocket;
	weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), transformRules, RHandSocket);

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

bool UCWeaponComponent::IsPlayingAnimAction()
{
	return OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying();
}

void UCWeaponComponent::SetKatanaMode()
{
	SetMode(EWeaponType::Katana);
}

void UCWeaponComponent::TestWeaponMode()
{
	//TODO:
//PlayerWeaponComponent 에 Asset추가
// Enum  추가
//InputAction 변수이름 변경
//
}

void UCWeaponComponent::SetUnarmedMode()
{
	UnEquip(CurrentWeaponType);
	ChangeWeaponType(EWeaponType::Max);
}

void UCWeaponComponent::SetMode(EWeaponType WeaponType)
{
	if (IsPlayingAnimAction()) return;

	EWeaponType prevType = WeaponType;

	if (CurrentWeaponType==WeaponType)
	{
		UE_LOG(LogTemp, Warning, TEXT("현재 무기와 같은 무기입니다 장착해제."));
		SetUnarmedMode();
		return;
	}
	else if (IsUnArmed() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("현재 무기와 같은 무기입니다 장착해제."));
		UnEquip(CurrentWeaponType);
	}

	UE_LOG(LogTemp, Warning, TEXT("다른 무기를 선택하였습니다."));
	UCWeaponAsset* asset = GetWeaponAsset(WeaponType);
	if (asset)
	{
		Equip(WeaponType);
	}
}

void UCWeaponComponent::ChangeWeaponType(EWeaponType WeaponType)
{
	EWeaponType prev = CurrentWeaponType;
	CurrentWeaponType = WeaponType;

	if (OnWeaponTypeChanged.IsBound())
		OnWeaponTypeChanged.Broadcast(prev, WeaponType);
}

void UCWeaponComponent::ActivateWeapon(EWeaponType WeaponType)
{
	if (WeaponType == EWeaponType::Katana)// 카타나일 경우 예외처리
	{
		UMeshComponent* LeftMesh = GetWeaponAsset(WeaponType)->GetWeapon()->GetLeftMesh();
		if (!LeftMesh) return;
		LeftMesh->SetVisibility(true);
	}

	UMeshComponent* RightMesh = GetWeaponAsset(WeaponType)->GetWeapon()->GetRightMesh();
	if (!RightMesh) return;
	RightMesh->SetVisibility(true);
}

void UCWeaponComponent::DeActivateWeapon(EWeaponType WeaponType)
{
	if (IsPlayingAnimAction()) return;

	USkeletalMeshComponent* OwnerMesh = OwnerCharacter->GetMesh();
	if (!OwnerMesh) return;

	if (WeaponType == EWeaponType::Katana)
	{
		UMeshComponent* LeftMesh = GetWeaponAsset(WeaponType)->GetWeapon()->GetLeftMesh();
		if ( !LeftMesh) return;

		FName LHolsterSocket = GetWeaponAsset(WeaponType)->GetEquipmentData().LHolsterSocket;
		LeftMesh->SetVisibility(false);
		LeftMesh->AttachToComponent(OwnerMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, LHolsterSocket);
	}

	UMeshComponent* RightMesh = GetWeaponAsset(WeaponType)->GetWeapon()->GetRightMesh();
	if (!RightMesh) return;

	FName RHolsterSocket = GetWeaponAsset(WeaponType)->GetEquipmentData().RHolsterSocket;
	RightMesh->AttachToComponent(OwnerMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, RHolsterSocket);
	RightMesh->SetVisibility(false);


	ChangeWeaponType(EWeaponType::Max); ////??
}


void UCWeaponComponent::Equip(EWeaponType WeaponType)
{
	ChangeWeaponType(WeaponType);

	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);

	if (!asset->GetEquipmentData().bCanMove)
		MovementComp->DisableMovment();

	if (!asset->GetEquipmentData().bCanRotate)
		MovementComp->DisableControlRotation();

	OwnerCharacter->PlayAnimMontage(GetWeaponAsset(CurrentWeaponType)->GetEquipmentData().EquipMontage);
	ActivateWeapon(CurrentWeaponType);
}

void UCWeaponComponent::UnEquip(EWeaponType WeaponType)
{
	DeActivateWeapon(WeaponType);
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
}


