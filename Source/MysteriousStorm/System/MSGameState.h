// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MSGameState.generated.h"

class UMSItemData;
class AMSItemActor;
/**
 * 
 */
UCLASS()
class MYSTERIOUSSTORM_API AMSGameState : public AGameStateBase
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnActorForwardOffset = 300.0f;

public:

	UFUNCTION(BlueprintCallable)
	bool TrySpawnItemActorFromData(UMSItemData* InItemData, AActor* SpawnAroundTarget, AMSItemActor*& OutItemActor, bool bGroundClamp = false);
};
