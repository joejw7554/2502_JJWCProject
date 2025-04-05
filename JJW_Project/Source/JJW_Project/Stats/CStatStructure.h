#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CStatStructure.generated.h"


USTRUCT()
struct FStatsStructure
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Strength = 1.f;

	UPROPERTY(EditAnywhere)
	float Defense = 1.f;

	FStatsStructure()
	{
		Strength = 1.f;
		Defense = 1.f;
	}
};

UCLASS()
class JJW_PROJECT_API UCStatStructure : public UObject
{
	GENERATED_BODY()
};
