#include "CPlayerState.h"
#include "Inventory/CInventoryComponent.h"

ACPlayerState::ACPlayerState()
{
	PrimaryActorTick.bCanEverTick = false;

	InventoryComponent = CreateDefaultSubobject<UCInventoryComponent>(TEXT("InventoryComponent"));
}