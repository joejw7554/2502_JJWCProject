#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInventorySlot.h"
#include "CInventoryComponent.generated.h"


UCLASS()
class JJW_PROJECT_API UCInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCInventoryComponent();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool AddItemToInventory(FItemStructure* InItemData);

	bool CheckInventoryFull();

	

protected:
	virtual void BeginPlay() override;


private:
	UCInventorySlot* FindEmptySlot();

private:
	UPROPERTY(VisibleAnywhere)
	TMap<TEnumAsByte<EInvenSlotOrder>, class UCInventorySlot*> InventorySlots;

	UPROPERTY(EditDefaultsOnly)
	uint8 InventoryMaxSize = 10;
};
