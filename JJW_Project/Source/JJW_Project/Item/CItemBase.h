#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CItemBase.generated.h"

UCLASS(Abstract)
class JJW_PROJECT_API ACItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACItemBase();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void UseItem();
	void ItemWave(float InDeltaTime);

	UFUNCTION()
	void OnItemHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* ItemCollision;

	UPROPERTY(EditDefaultsOnly)
	float WaveHeight = 150.f;

	bool bHitFloor=false;

	float ElapsedTime = 0.f;
};
