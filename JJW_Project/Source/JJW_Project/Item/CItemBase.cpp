#include "CItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ACItemBase::ACItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

	//ItemCollision으로 플레이와 접촉했는지 추적할꺼고
	//ItemMesh로 충돌을 체크하고 충돌이 감지되면 FMath::Cos 로 웨이브 움직임을 줄꺼다

	ItemMesh= CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");
	Tags.Add("Item");

	SetRootComponent(ItemMesh);
	ItemMesh->SetCollisionProfileName("Custom");
	ItemMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	ItemMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Ignore);
	ItemMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	ItemMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	ItemMesh->SetSimulatePhysics(true);
	ItemMesh->SetNotifyRigidBodyCollision(true);
	ItemMesh->BodyInstance.bLockYTranslation = false;
	ItemMesh->BodyInstance.bLockXTranslation = false;
}

void ACItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bHitFloor)
		ItemWave(DeltaTime);

}

void ACItemBase::BeginPlay()
{
	Super::BeginPlay();

	ItemMesh->OnComponentHit.AddDynamic(this, &ACItemBase::OnItemHit);

	
}

void ACItemBase::ItemWave(float InDeltaTime)
{
	ElapsedTime += InDeltaTime;
	float Zlocation = ((FMath::Sin(ElapsedTime) + 1) *0.5) * WaveHeight +25.f;
	ItemMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, Zlocation));
}

void ACItemBase::OnItemHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!OtherActor->ActorHasTag("Player") && !OtherActor->ActorHasTag("Enemy"))
	{
		bHitFloor = true;
		ItemMesh->SetSimulatePhysics(false);
	}
}

//아이템 스폰 규칙
	//몬스터가 Item PID 값을 가지고 있는다 Done
	// 아이템 매니저한테 PID를 넘겨주고 아이템 데이터를 가져온다 Done
	//드랍 구조체를 만들어서 PID, 확률, 갯수를 몬스터마다 부여한다
	//몬스터가 받은 데이터로 스폰해준다
