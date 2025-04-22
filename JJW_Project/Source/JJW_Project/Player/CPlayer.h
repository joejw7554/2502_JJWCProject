#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../Components/CWeaponComponent.h"
#include "Stats/CStatStructure.h"

#include "GenericTeamAgentInterface.h"

#include "CPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthBarUpdate, float, HealthPercent);


UCLASS()
class JJW_PROJECT_API ACPlayer : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	FHealthBarUpdate OnHealthBarUpdate;

	ACPlayer();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FGenericTeamId GetGenericTeamId() const override { return FGenericTeamId(TeamID); }

public: //Getter
	FORCEINLINE UCWeaponComponent* GetWeaponComponent() { return Weapon; }
	FORCEINLINE float GetCurrentHealthPercent() { return CurrentHealth / MaxHealth; }
	FORCEINLINE float GetCurrentHealth() { return CurrentHealth; }
	FORCEINLINE void IncreamentHealth(float InHealth) { SetCurrentHealth(InHealth); }
	FORCEINLINE class ACPlayerState* GetPlayerState() { return CPlayerState; }


private:
	void SetCurrentHealth(float InHealth);

protected:
	virtual void BeginPlay() override;


private:
	void InitializePlayerEnhnacedInput();

	void PickupItem();

	void ToggleInventoryMenu();

	void ToggleStatMenu();

	UFUNCTION()
	void OnPlayerTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	void PlayHitReactionMontage(AActor* DamageCauser, float InDamageAmount);

	UFUNCTION()
	void OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* InputMappingContext;


	//Movement Action///////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_DodgeAction;


	//WeaponEquip Action//////////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_KatanaAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_TestWeapon;

	// Attack Function/////////////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_BasicAttackAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SKill_Q;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SKill_W;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SKill_E;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SKill_R;

	//Utility Action//////////////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_PickupAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_InventoryAction;


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_StatAction;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* SphereComponent;

private:
	UPROPERTY(EditDefaultsOnly)
	uint8 TeamID = 1;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montage|Hit")
	float HitMontagePlayRate = 1.5f;

	UPROPERTY(VisibleAnywhere)
	FRotator CursorTargetRotation;


	UPROPERTY(VisibleAnywhere)
	UCWeaponComponent* Weapon;

	UPROPERTY(VisibleAnywhere)
	class UCMovementComponent_Player* Movement;


	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere)
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere)
	float TargetHealth;

	UPROPERTY(VisibleAnywhere)
	bool bInterpolatingHealth = false;
	//Cached
	UPROPERTY()
	class ACPlayerState* CPlayerState;

	UPROPERTY()
	class ACHUD* HUD;

	bool bIsDead = false;
};
