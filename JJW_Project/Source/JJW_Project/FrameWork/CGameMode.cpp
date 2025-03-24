#include "FrameWork/CGameMode.h"
#include "Components/CItemFactoryComponent.h"
#include "FrameWork/CHUD.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<ACharacter> playerClass(L"/Script/Engine.Blueprint'/Game/Blueprints/Player/BP_CPlayer.BP_CPlayer_C'");

	if (playerClass.Succeeded())
		DefaultPawnClass = playerClass.Class;

	ConstructorHelpers::FClassFinder<APlayerState>playerStateClass(L"/Script/Engine.Blueprint'/Game/Blueprints/Player/BP_CPlayerState.BP_CPlayerState_C'");
	if(playerStateClass.Succeeded())
		PlayerStateClass = playerStateClass.Class;

	ConstructorHelpers::FClassFinder<ACHUD> hudClass(L"/Script/Engine.Blueprint'/Game/Blueprints/Framework/BP_CHUD.BP_CHUD_C'");
	if (hudClass.Succeeded())
		HUDClass = hudClass.Class;


	ItemFactoryComponent = CreateDefaultSubobject<UCItemFactoryComponent>("ItemFactoryComponent");
}
