// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MSBackpackComponent.generated.h"

class AMSItemActor;
class UMSItemData;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent) )
class MYSTERIOUSSTORM_API UMSBackpackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMSBackpackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	TMap<UMSItemData*, int32> Items;

	UPROPERTY(BlueprintReadWrite)
	TArray<UMSItemData*> WeaponList;

// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	TArray<UMSItemData*> Tiles;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#pragma region CachedPickUpList
public:

protected:
	UPROPERTY(BlueprintReadWrite)
	TMap<UMSItemData*, int32> CachedItems;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<UMSItemData*, AMSItemActor*> CachedPickUpList;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CachedRowNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CachedColumnNumber;

public:
	UFUNCTION(BlueprintCallable)
	void AddToCachedPickUpList(AMSItemActor* NewItem);

	UFUNCTION(BlueprintCallable)
	void RemoveFromCachedPickUpList(AMSItemActor* TargetItem);

	const TMap<UMSItemData*, int32>& GetCachedItem() const {return CachedItems;}

	const TMap<UMSItemData*, AMSItemActor*>& GetCachedList() const {return CachedPickUpList; }

	void ClearCachedItem() { CachedItems.Empty(); }

	UFUNCTION(BlueprintCallable)
	void AddCachedItem(UMSItemData* NewItemData, int32 TopLeftIndex);
#pragma endregion

#pragma region Backpack
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RowNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ColumnNumber;

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBackpackChanged);
	UPROPERTY(BlueprintAssignable)
	FOnBackpackChanged OnBackpackChanged;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBackpackOpened);
	UPROPERTY(BlueprintAssignable)
	FOnBackpackOpened OnBackpackOpened;

	UPROPERTY()
	bool NeedRefresh;

	UFUNCTION(BlueprintCallable)
	void OpenBackpack();

	UFUNCTION(BlueprintCallable)
	void CloseBackpack();

	UFUNCTION(BlueprintCallable)
	bool CanAddThisItem(UMSItemData* NewItemData, bool bIsBackpack) const;

	UFUNCTION(BlueprintCallable)
	void AddBackpackItem(UMSItemData* NewItemData, int32 TopLeftIndex);

	UFUNCTION(BlueprintCallable)
	const TMap<UMSItemData*, int32>& GetItems() const { return Items; }

	UFUNCTION(BlueprintCallable)
	void RemoveItem(UMSItemData* TargetItem, bool bIsBackpack);
#pragma endregion
};
