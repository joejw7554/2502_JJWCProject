#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AN_Attachment.generated.h"

UCLASS()
class JJW_PROJECT_API UAN_Attachment : public UAnimNotify
{
	GENERATED_BODY()



protected:
	FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	UPROPERTY(EditAnywhere, Category="Setting")
	bool bAttachToHand;

	UPROPERTY()
	ACharacter* Owner;
};
