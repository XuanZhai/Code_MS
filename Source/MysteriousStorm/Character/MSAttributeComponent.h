// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MSAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSTERIOUSSTORM_API UMSAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMSAttributeComponent();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute")
	float MaxHealth;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute")
	float InvincibleTime;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute")
	float MoveSpeed;
	

protected:

	float currentHealth;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
