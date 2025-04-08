#include "Item/Potions/CPotionBase_Defense.h"
#include "Player/CPlayerState.h"
#include "Player/CPlayer.h"
#include "Stats/CStatComponent.h"

void ACPotionBase_Defense::UseItem(ACPlayer* InOwner)
{
    if (!InOwner) return;

    ACPlayerState* state= InOwner->GetPlayerState();
	if (!state) return;

    UCStatComponent* statCompo= state->GetStatComponent();
	if (!statCompo) return;

	statCompo->ApplyBuff(FName("Defense"), PotionData.EffectValue, PotionData.Duration);
}
