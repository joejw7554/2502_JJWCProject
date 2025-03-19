#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CItemStructure.generated.h"


USTRUCT()
struct FItemStructure : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) //인벤토리에서 찾을떄 숫자로 비교할꺼임
	uint8 ItemID;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	FString Description;

	UPROPERTY(EditAnywhere)
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere)
	int32 Price;

	UPROPERTY(EditAnywhere)
	int32 MaxStack;

	UPROPERTY(EditAnywhere)
	bool bStackable;

	UPROPERTY(EditAnywhere)
	bool bConsumable;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ACItemBase> ItemClass;

	FItemStructure()
	{
		ItemID = 0;
		Name = FString(TEXT("None"));
		Description = FString(TEXT("None"));
		Thumbnail = nullptr;
		Price = 0;
		MaxStack = 0;
		bStackable = false;
		bConsumable = false;
		ItemClass = nullptr;
	}
};


USTRUCT()
struct FItemDropTable : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	uint8 ItemID;

	UPROPERTY(EditAnywhere)
	uint8 SpawnCount;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.1", ClampMax = "1.0"))
	float DropRate;
};

UCLASS()
class JJW_PROJECT_API UCItemStructure : public UObject
{
	GENERATED_BODY()
	
};
