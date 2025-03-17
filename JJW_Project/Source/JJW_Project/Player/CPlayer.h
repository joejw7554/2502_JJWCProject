#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Components/CMovementComponent.h"
#include "../Components/CWeaponComponent.h"

#include "CPlayer.generated.h"

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
	FORCEINLINE float GetCurrentHealthPercent() { return CurrentHealth/MaxHealth; }


protected:
	virtual void BeginPlay() override;


private:
	void InitializePlayerEnhnacedInput();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SprintAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_DodgeAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_KatanaAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_TestWeapon;

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

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FollowCamera;

private:
	UPROPERTY(VisibleAnywhere)
	UCMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere)
	UCWeaponComponent* Weapon;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere)
	float CurrentHealth = MaxHealth;
};
