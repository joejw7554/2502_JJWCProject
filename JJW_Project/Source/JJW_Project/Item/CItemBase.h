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

	void InitializeItemData(FItemStructure InItemData) { ItemData = InItemData; }
	FItemStructure& GetItemData() { return ItemData; }

protected:
	virtual void BeginPlay() override;
	virtual void UseItem() {} //이거 인터페이스로 뺼 생각 해봐야함 잡템은 사용이 불가능하잖아? 그럼 인터페이스로 빼서 사용가능한 아이템만 사용하게끔 해야할지도?
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
