#include "CPlayer.h"

#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"


#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"


ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* playerController = Cast<APlayerController>(GetController());

	if (playerController)
	{
		if (playerController->GetLocalPlayer())
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());

			if (Subsystem && InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}

}

void ACPlayer::Move(const FInputActionValue& Value)
{
	FVector2D val = Value.Get<FVector2D>();

	FRotator yawRotator = FRotator(0.f, GetControlRotation().Yaw,0.f);

	FVector forward = FRotationMatrix(yawRotator).GetUnitAxis(EAxis::X);
	FVector right = FRotationMatrix(yawRotator).GetUnitAxis(EAxis::Y);

	AddMovementInput(forward, val.Y);
	AddMovementInput(right, val.X);

}

void ACPlayer::Look(const FInputActionValue& Value)
{
	FVector2D val = Value.Get<FVector2D>();

	AddControllerYawInput(val.X);
	AddControllerPitchInput(-val.Y);

}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPlayer::Move);
	enhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPlayer::Look);
}

