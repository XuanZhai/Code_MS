// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "MSCachedPickUpItemWidget.h"
#include "MSBackpackWidget.generated.h"


class UMSBackpackComponent;
/**
 * 
 */
UCLASS()
class MYSTERIOUSSTORM_API UMSBackpackWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMSBackpackComponent* BackpackComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TileSize = 0.0f;

#pragma region CachedPickUpList

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UMSCachedPickUpItemWidget> CachedItemClass;

	UPROPERTY(meta = (BindWidget))
	UListView* CachedPickUpListView;

	UFUNCTION(BlueprintCallable)
	void RefreshCachedPickUpListView();
#pragma endregion

};
