#include "CWeaponComponent.h"

#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"

#include "CMovementComponent.h"
#include "Weapons/CWeaponBase.h"
#include "Weapons/CWeaponAsset.h"
#include "Weapons/CSkillStructure.h"

#include "CSkill_Q.h"
#include "CSkill_W.h"
#include "CSkill_E.h"
#include "CSkill_R.h"
#include "CSkill_BasicCombo.h"

UCWeaponComponent::UCWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	WeaponAssets.Reserve((int8)EWeaponType::Max);
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
	params.Instigator = OwnerCharacter;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACWeaponBase* weapon = GetWorld()->SpawnActor<ACWeaponBase>(asset->GetWeaponClass(), params);
	if (!weapon) return;

	asset->SetWeapon(weapon);
	UCSkill_BasicCombo* basic = asset->GetWeapon()->GetBasicCombo();
	UCSkill_Q* skillQ = asset->GetWeapon()->GetSkill_Q();
	UCSkill_W* skillW = asset->GetWeapon()->GetSkill_W();
	UCSkill_E* skillE = asset->GetWeapon()->GetSkill_E();
	UCSkill_R* skillR = asset->GetWeapon()->GetSkill_R();

	if (basic)
		basic->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::BasicCombo);

	if (skillQ)
		skillQ->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::Q);

	if (skillW)
		skillW->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::W);

	if (skillE)
		skillE->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::E);

	if (skillR)
		skillR->InitialzeSkillData(&(asset->GetWeaponSkillSet()), ESkillKey::R);

	weapon->GetRightMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().RHolsterSocket);

	if (asset->GetWeaponType() == EWeaponType::Katana)
		weapon->GetLeftMesh()->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, asset->GetEquipmentData().LHolsterSocket);

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

void UCWeaponComponent::EnableWeaponCollision()
{
	ACWeaponBase* weapon = GetCurrentWeapon();
	if (!weapon) return;

	weapon->GetRightMesh()->SetCollisionProfileName("OverlapAllDynamic");
	if (CurrentWeaponType == EWeaponType::Katana)
		weapon->GetLeftMesh()->SetCollisionProfileName("OverlapAllDynamic");
}

void UCWeaponComponent::DisableWeaponCollision()
{
	ACWeaponBase* weapon = GetCurrentWeapon();
	if (!weapon) return;

	weapon->GetRightMesh()->SetCollisionProfileName("NoCollision");
	if (CurrentWeaponType == EWeaponType::Katana)
		weapon->GetLeftMesh()->SetCollisionProfileName("NoCollision");

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

ACWeaponBase* UCWeaponComponent::GetCurrentWeapon()
{
	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);

	return asset->GetWeapon();
}

bool UCWeaponComponent::IsPlayingAnimAction()
{
	return OwnerCharacter->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying();
}

void UCWeaponComponent::SetKatanaMode()
{
	SetMode(EWeaponType::Katana);
}

void UCWeaponComponent::TestWeaponMode() //////////////NEED TO IMPLEMENTED
{
	//TODO:
//PlayerWeaponComponent 에 Asset추가
// Enum  추가
//InputAction 변수이름 변경
//
}

void UCWeaponComponent::DoSkill(ESkillKey InKey)
{
	if (IsUnArmed()) return;

	ACWeaponBase* weapon = GetCurrentWeapon();
	if (!OwnerCharacter) return;
	if (!weapon) return;

	UCMovementComponent* movementComp = OwnerCharacter->GetComponentByClass<UCMovementComponent>();
	if (!movementComp) return;

	movementComp->DisableMovment();

	ESkillKey PrevSkill = CurrentSkillKey;

	if (PrevSkill != InKey)
		ResetComboIndex();

	CurrentSkillKey = InKey;

	switch (CurrentSkillKey)
	{
	case ESkillKey::BasicCombo:
		weapon->GetBasicCombo()->PerformSkill(bEnableCombo, CurrentComboIndex, OwnerCharacter);
		break;

	case ESkillKey::Q:
		weapon->GetSkill_Q()->PerformSkill(bEnableCombo, CurrentComboIndex, OwnerCharacter);
		break;

	case ESkillKey::W:
		weapon->GetSkill_W()->PerformSkill(bEnableCombo, CurrentComboIndex, OwnerCharacter);
		break;

	case ESkillKey::E:
		weapon->GetSkill_E()->PerformSkill(bEnableCombo, CurrentComboIndex, OwnerCharacter);
		break;

	case ESkillKey::R:
		weapon->GetSkill_R()->PerformSkill(bEnableCombo, CurrentComboIndex, OwnerCharacter);
		break;
	default:
		break;
	}
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

	if (CurrentWeaponType == WeaponType)
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
		if (!LeftMesh) return;

		FName LHolsterSocket = GetWeaponAsset(WeaponType)->GetEquipmentData().LHolsterSocket;
		LeftMesh->SetVisibility(false);
		LeftMesh->AttachToComponent(OwnerMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, LHolsterSocket);
		LeftMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	UMeshComponent* RightMesh = GetWeaponAsset(WeaponType)->GetWeapon()->GetRightMesh();
	if (!RightMesh) return;

	FName RHolsterSocket = GetWeaponAsset(WeaponType)->GetEquipmentData().RHolsterSocket;
	RightMesh->AttachToComponent(OwnerMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, RHolsterSocket);
	RightMesh->SetVisibility(false);
	RightMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ChangeWeaponType(EWeaponType::Max); ////??
}


void UCWeaponComponent::Equip(EWeaponType WeaponType)
{
	if (IsPlayingAnimAction()) return;

	ChangeWeaponType(WeaponType);

	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);

	OwnerCharacter->PlayAnimMontage(GetWeaponAsset(CurrentWeaponType)->GetEquipmentData().EquipMontage);
	ActivateWeapon(CurrentWeaponType);

	MovementComp->DisableMovment();
}

void UCWeaponComponent::UnEquip(EWeaponType WeaponType)
{
	DeActivateWeapon(WeaponType);
}

void UCWeaponComponent::Begin_Equip()
{
	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);
	MovementComp->DisableMovment();

	AttachWeaponToHand(CurrentWeaponType);
}

void UCWeaponComponent::End_Equip()
{
	UCWeaponAsset* asset = GetWeaponAsset(CurrentWeaponType);
	MovementComp->EnableMovement();
}


