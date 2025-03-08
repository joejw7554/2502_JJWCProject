#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWeaponStructure.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Katana = 0, Test,Max
};



USTRUCT()
struct FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	class UAnimMontage* EquipMontage;

	UPROPERTY(EditAnywhere)
	float Equip_PlayRate;

	UPROPERTY(EditAnywhere)
	bool bCanMove;

	UPROPERTY(EditAnywhere)
	bool bCanRotate;

	UPROPERTY(EditAnywhere)
	FName RHandSocket;

	UPROPERTY(EditAnywhere)
	FName RHolsterSocket;

	UPROPERTY(EditAnywhere, Category="Optional")
	FName LHandSocket;

	UPROPERTY(EditAnywhere, Category = "Optional")
	FName LHolsterSocket;
};



UCLASS()
class JJW_PROJECT_API UCWeaponStructure : public UObject
{
	GENERATED_BODY()
	
};
