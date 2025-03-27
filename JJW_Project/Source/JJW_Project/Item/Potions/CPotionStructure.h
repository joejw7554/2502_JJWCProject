#pragma once


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "CPotionStructure.generated.h"

UENUM(BlueprintType)
enum class EPotionType : uint8
{
	HP, Speed, Power, Defense,
};

UENUM(BlueprintType)
enum class EPotionSize : uint8
{
	Small, Medium, Large,
};

USTRUCT()
struct FPotionStructure 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EPotionType PotionType;

	UPROPERTY(EditAnywhere)
	EPotionSize PotionSize;

	UPROPERTY(EditAnywhere)
	float Duration;

	UPROPERTY(EditAnywhere)
	float EffectValue;


	FPotionStructure()
	{
		PotionType = EPotionType::HP;
		PotionSize = EPotionSize::Small;
		Duration = 3.f;
		EffectValue = 1.f;
	}
};

