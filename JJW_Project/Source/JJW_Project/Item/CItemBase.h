#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CItemBase.generated.h"

UCLASS(Abstract, NotBlueprintable)
class JJW_PROJECT_API ACItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACItemBase();

protected:
	virtual void BeginPlay() override;
	virtual void UseItem();

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* ItemCollision;
};
