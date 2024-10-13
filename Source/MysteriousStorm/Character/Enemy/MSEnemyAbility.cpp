// Fill out your copyright notice in the Description page of Project Settings.


#include "MSEnemyAbility.h"

#include "MysteriousStorm/Character/MSCharacter.h"

bool UMSEnemyAbility::TryActivateAbility_Implementation()
{
	if (Super::TryActivateAbility_Implementation())
	{
		auto Player = Cast<AMSCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

		if (!Player)
		{
			return false;
		}
		
		AMSEnemyCharacter* EnemyPlayer = Cast<AMSEnemyCharacter>(OwnerEnemy);
		Player->GetAttributeComponent()->Hurt(OwnerEnemy, EnemyPlayer->GetEnemyConfig()->AbilityDamage[GetIndex()]);
		return true;
	}
	return false;
}

bool UMSEnemyAbility::CheckPrecondition_Implementation()
{
	auto Player = Cast<AMSCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!Player)
	{
		return false;
	}
	return Super::CheckPrecondition_Implementation() && (FVector::Distance(Player->GetActorLocation(),
	                                                                       OwnerEnemy->GetActorLocation()) < 100);
}


