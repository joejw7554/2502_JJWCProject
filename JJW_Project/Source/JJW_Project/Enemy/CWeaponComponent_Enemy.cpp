#include "Enemy/CWeaponComponent_Enemy.h"

void UCWeaponComponent_Enemy::ChangeWeaponType(EWeaponType WeaponType)
{
	Super::ChangeWeaponType(WeaponType);

	bool bNewIsArmed = (CurrentWeaponType != EWeaponType::Max);
	OnAIWeaponStateChanged.Broadcast(bNewIsArmed);
}
