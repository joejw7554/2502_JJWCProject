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

USTRUCT(BlueprintType)
struct FPotionStructure 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EPotionType PotionType;

	UPROPERTY(EditAnywhere)
	float Duration;

	UPROPERTY(EditAnywhere)
	float EffectValue;
};

