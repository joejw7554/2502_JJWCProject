#include "CPlayer.h"

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

	//Components
	{
		Movement = CreateDefaultSubobject<UCMovementComponent>("MovementComponent");
		State = CreateDefaultSubobject<UCStateComponent>("StateComponent");
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->bEnableCameraLag = true;
	SpringArm->SocketOffset = FVector(0,0,80);
	SpringArm->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	FollowCamera->SetupAttachment(SpringArm);

	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	InitializePlayerEnhnacedInput();

	if(Movement)
	Movement->DisableControlRotation();

	State->OnStateChange.AddDynamic(this, &ACPlayer::OnStateChanged);
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

void ACPlayer::OnStateChanged(EState InPrevState, EState InNewState)
{
	switch (InNewState)
	{
	case EState::Idle:

		break;
	case EState::Attack:

		break;
	case EState::Dodge:

		break;
	case EState::Damaged:

		break;
	case EState::Dead:

		break;
	case EState::Max:

		break;

	default:
		break;
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

	if(IA_MoveAction)
	enhancedInput->BindAction(IA_MoveAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::MoveAction);

	if(IA_LookAction)
	enhancedInput->BindAction(IA_LookAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::LookAction);

	if(IA_SprintAction)
	enhancedInput->BindAction(IA_SprintAction, ETriggerEvent::Triggered, Movement, &UCMovementComponent::SprintAction);

}

