#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CItemStructure.generated.h"

USTRUCT()
struct FItemStructure : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	FString Description;

	UPROPERTY(EditAnywhere) //인벤토리에서 찾을떄 숫자로 비교할꺼임
	int32 ItemID;

	UPROPERTY(EditAnywhere)
	int32 Price;

	UPROPERTY(EditAnywhere)
	int32 MaxStack;

	UPROPERTY(EditAnywhere)
	bool bIsStackable;

	UPROPERTY(EditAnywhere)
	bool bIsConsumable;

	UPROPERTY(EditAnywhere)
	bool bIsUsable;

	/*UPROPERTY(EditAnywhere)
	TSubclassOf<class ACItemBase> ItemClass;*/
};

UCLASS()
class JJW_PROJECT_API UCItemStructure : public UObject
{
	GENERATED_BODY()
	
};
