#include "Inventory/CInventoryComponent.h"
#include "CInventorySlot.h"

UCInventoryComponent::UCInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UCInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UCInventorySlot* slot = CreateDefaultSubobject<UCInventorySlot>("InventorySlot");
	
}
