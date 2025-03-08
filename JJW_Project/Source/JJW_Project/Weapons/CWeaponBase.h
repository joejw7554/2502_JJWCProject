#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CWeaponBase.generated.h"

UCLASS(Abstract)
class JJW_PROJECT_API ACWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	ACWeaponBase();

protected:
	virtual void BeginPlay() override;

public:
	UMeshComponent* GetRightMesh() { return RightHandWeaponMesh ? RightHandWeaponMesh : nullptr; }
	UMeshComponent* GetLeftMesh() { return LeftHandWeaponMesh ? LeftHandWeaponMesh : nullptr; }
	ACharacter* GetWeaponOwner() { return OwnerCharacter; }

	//void OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	UStaticMeshComponent* RightHandWeaponMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	UStaticMeshComponent* LeftHandWeaponMesh;


private:
	class ACharacter* OwnerCharacter;

	UPROPERTY(VisibleAnywhere, Category="Skill")
	class UCSkillComponent* SkillComponent;
};
