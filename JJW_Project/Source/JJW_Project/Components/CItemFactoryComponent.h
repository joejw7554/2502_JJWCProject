#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/CItemStructure.h"
#include "CItemFactoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JJW_PROJECT_API UCItemFactoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCItemFactoryComponent();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:	
	class ACItemBase* GetItem(EItemType InType);


protected:
	virtual void BeginPlay() override;

private:
	TMap<EItemType, FItemStructure> ItemList;
};
