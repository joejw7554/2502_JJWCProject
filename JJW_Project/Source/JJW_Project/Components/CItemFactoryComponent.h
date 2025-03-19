#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/CItemStructure.h"
#include "Enemy/CEnemyBase.h"
#include "CItemFactoryComponent.generated.h"


UCLASS()
class JJW_PROJECT_API UCItemFactoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCItemFactoryComponent();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	
	void CreateDropItem(const EEnemyType InType, const FVector& InLocation);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UDataTable* ItemTable;

private:
	UPROPERTY(EditDefaultsOnly)
	class ACDropItemDataManager* DataManager;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ACDropItemDataManager> DataManagerClass;
};
