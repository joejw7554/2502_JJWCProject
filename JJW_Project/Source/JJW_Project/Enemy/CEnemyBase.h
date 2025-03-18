#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(EditAnywhere, Category="Item")
	TArray<uint8> DropItemList;

private:
};
