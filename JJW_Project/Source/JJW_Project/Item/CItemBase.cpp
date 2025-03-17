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
	ItemCollision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
}

void ACItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}


