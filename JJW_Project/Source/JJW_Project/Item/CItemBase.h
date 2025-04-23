#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CItemStructure.h"
#include "CItemBase.generated.h"

UCLASS(Abstract)
class JJW_PROJECT_API ACItemBase : public AActor
{
	GENERATED_BODY()

public:
	ACItemBase();
	virtual void Tick(float DeltaTime) override;

	void InitializeItemData(ACItemBase* InItemInstance, FItemStructure InItemData) { ItemData = InItemData; ItemData.ItemInstance = InItemInstance; }
	FItemStructure& GetItemData() { return ItemData; }

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	void ItemWave(float InDeltaTime);

	UFUNCTION()
	void OnItemHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	//Default Properties
protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditDefaultsOnly)
	float ForceAmount = 800.f;

	UPROPERTY(EditDefaultsOnly)
	float WaveHeight = 150.f;

	bool bHitFloor = false;

	float ElapsedTime = 0.f;
	
	//Common Properties
protected:
	UPROPERTY(EditDefaultsOnly, Category="Item Property")
	float EffectiveValue = 1.f;

private:
	UPROPERTY()
	FItemStructure ItemData;
};
