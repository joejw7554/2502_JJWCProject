#include "CPlayerState.h"
#include "Inventory/CInventoryComponent.h"
#include "Player/CPlayer.h"

ACPlayerState::ACPlayerState()
{
	PrimaryActorTick.bCanEverTick = false;

	InventoryComponent = CreateDefaultSubobject<UCInventoryComponent>(TEXT("InventoryComponent"));
}

void ACPlayerState::BeginPlay()
{
	Super::BeginPlay();

	InventoryComponent->ResetInventory(Cast<ACPlayer>(GetOwner()));
}
