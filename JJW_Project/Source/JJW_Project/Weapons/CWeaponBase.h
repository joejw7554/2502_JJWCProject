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

	class UCSkill_BasicCombo* GetBasicCombo() { return BasicCombo; }
	class UCSkill_Q* GetSkill_Q() { return Skill_Q; }
	class UCSkill_W* GetSkill_W() { return Skill_W; }
	class UCSkill_E* GetSkill_E() { return Skill_E; }
	class UCSkill_R* GetSkill_R() { return Skill_R; }

protected:
	friend class UCAnimNotify_SetDamage;
	void SetDamage(float InDamage) { Damage = InDamage; }

	UFUNCTION()
	void OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	ACharacter* GetWeaponOwner() { return OwnerCharacter; }


protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	UStaticMeshComponent* RightHandWeaponMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	UStaticMeshComponent* LeftHandWeaponMesh;



	//Skills////////
	UPROPERTY(VisibleAnywhere, Category = "SKills")
	class UCSkill_BasicCombo* BasicCombo;

	UPROPERTY(VisibleAnywhere, Category = "SKills")
	class UCSkill_Q* Skill_Q;

	UPROPERTY(VisibleAnywhere, Category = "SKills")
	class UCSkill_W* Skill_W;

	UPROPERTY(VisibleAnywhere, Category = "SKills")
	class UCSkill_E* Skill_E;

	UPROPERTY(VisibleAnywhere, Category = "SKills")
	class UCSkill_R* Skill_R;


private:
	class ACharacter* OwnerCharacter;

private:
	UPROPERTY(VisibleAnywhere)
	float Damage = 0;
};
