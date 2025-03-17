#include "FrameWork/CGameMode.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<ACharacter> playerClass(L"/Script/Engine.Blueprint'/Game/Blueprints/Player/BP_CPlayer.BP_CPlayer_C'");

	if (playerClass.Succeeded())
	{
		DefaultPawnClass = playerClass.Class;
	}
}
