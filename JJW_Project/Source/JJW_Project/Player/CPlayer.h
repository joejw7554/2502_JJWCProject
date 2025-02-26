#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Components/CStateComponent.h"
#include "../Components/CMovementComponent.h"

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


public: 
	void OnDodge();

protected:
	virtual void BeginPlay() override;


private:
	void InitializePlayerEnhnacedInput();

	UFUNCTION()
	void OnStateChanged(EState InPrevState, EState InNewState);


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

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FollowCamera;




private:
	UPROPERTY(VisibleAnywhere)
	UCMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere)
	UCStateComponent* State;
};
