#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/CItemStructure.h"
#include "CItemFactoryComponent.generated.h"


UCLASS()
class JJW_PROJECT_API UCItemFactoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCItemFactoryComponent();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	
	UFUNCTION(BlueprintCallable)
	class ACItemBase* GetDropItem(const uint8 ID, FVector InLocation, FRotator InRotation);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UDataTable* ItemTable;
};
