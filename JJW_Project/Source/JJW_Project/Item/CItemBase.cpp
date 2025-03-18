#include "CItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ACItemBase::ACItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	ItemMesh= CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");
	ItemMesh->SetupAttachment(Root);

	ItemCollision = CreateDefaultSubobject<UBoxComponent>("ItemCollision");
	ItemCollision->SetupAttachment(ItemMesh);
	ItemCollision->SetBoxExtent(FVector(100.f, 100.f,100.f));
}

void ACItemBase::BeginPlay()
{
	Super::BeginPlay();

}

void ACItemBase::UseItem()
{

}

//아이템 스폰 규칙
	//몬스터가 Item PID 값을 가지고 있는다
	// 아이템 매니저한테 PID를 넘겨주고 아이템 데이터를 가져온다
	//드랍 구조체를 만들어서 PID, 확률, 갯수를 몬스터마다 부여한다
	//몬스터가 받은 데이터로 스폰해준다
