#include "CPlayerState.h"
#include "Inventory/CInventoryComponent.h"
#include "CPlayerController.h"
#include "Player/CPlayer.h"

ACPlayerState::ACPlayerState()
{
	PrimaryActorTick.bCanEverTick = false;

	InventoryComponent = CreateDefaultSubobject<UCInventoryComponent>(TEXT("InventoryComponent"));
}

void ACPlayerState::BeginPlay()
{
	Super::BeginPlay();
	
	ACPlayerController* controller = Cast<ACPlayerController>(GetOwner());
	if (!controller) return;

	OwnerCharacter = Cast<ACPlayer>(controller->GetPawn());
	
	InventoryComponent->ResetInventory(OwnerCharacter);
}
