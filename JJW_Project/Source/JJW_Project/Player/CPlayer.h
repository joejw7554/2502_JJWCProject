#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Components/CMovementComponent.h"
#include "../Components/CWeaponComponent.h"

#include "CPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryUpdate);

UCLASS()
class JJW_PROJECT_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public: //Getter
	FORCEINLINE UCWeaponComponent* GetWeaponComponent() { return Weapon; }
	FORCEINLINE float GetCurrentHealthPercent() { return CurrentHealth / MaxHealth; }


protected:
	virtual void BeginPlay() override;


private:
	void InitializePlayerEnhnacedInput();

	void PickupItem();

	void OpenInventoryMenu();
	void CloseInventoryMenu();


public:
	FInventoryUpdate OnInventoryUpdate;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* InputMappingContext;


	//Movement Action///////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SprintAction;

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

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FollowCamera;

private:
	UPROPERTY(VisibleAnywhere)
	FRotator CursorTargetRotation;

	UPROPERTY(VisibleAnywhere)
	UCMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere)
	UCWeaponComponent* Weapon;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere)
	float CurrentHealth = MaxHealth;

	UPROPERTY(EditAnywhere)
	class ACPlayerState* CPlayerState;
};
