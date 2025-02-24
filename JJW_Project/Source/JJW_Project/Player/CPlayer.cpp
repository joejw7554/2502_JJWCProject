#include "CPlayer.h"
#include "../Components/CMovementComponent.h"
#include "../Components/CStateComponent.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"




ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90,0));

	Movement = CreateDefaultSubobject<UCMovementComponent>("MovementComponent");

	State= CreateDefaultSubobject<UCStateComponent>("StateComponent");

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->bEnableCameraLag = true;
	SpringArm->bUsePawnControlRotation = true;
	

	GetCharacterMovement()->MaxWalkSpeed = 400;
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	FollowCamera->SetupAttachment(SpringArm);
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	InitializePlayerEnhnacedInput();

	if(Movement)
	Movement->DisableControlRotation();
}

void ACPlayer::InitializePlayerEnhnacedInput()
{
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

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!Movement) return;

	enhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::Move);
	enhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::Look);
}

