#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item/CItemStructure.h"
#include "CEnemyBase.generated.h"

UCLASS()
class JJW_PROJECT_API ACEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACEnemyBase();
	//virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void DropItem();


private:
	UPROPERTY(EditAnywhere, Category="Item")
	UDataTable* DropTable;

private:
};
