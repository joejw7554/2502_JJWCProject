#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CItemStructure.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	HP_Potion 	UMETA(DisplayName = "HP Portion"),
	DamageBoost UMETA(DisplayName = "Damage Boost"),
	ArmorBoost 	UMETA(DisplayName = "Armor Boost"),
	SpeedBoost 	UMETA(DisplayName = "Speed Boost"),
	Max UMETA(Hidden)
};


USTRUCT()
struct FItemStructure
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
	uint8 ItemID;

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
		Thumbnail = nullptr;
		Name = FString(TEXT("None"));
		Description = FString(TEXT("None"));
		ItemID = 0;
		Price = 0;
		MaxStack = 0;
		bStackable = false;
		bConsumable = false;
		ItemClass = nullptr;
	}
};

UCLASS()
class JJW_PROJECT_API UCItemStructure : public UObject
{
	GENERATED_BODY()
	
};
