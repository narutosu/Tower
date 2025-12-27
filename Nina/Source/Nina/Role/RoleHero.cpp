// Fill out your copyright notice in the Description page of Project Settings.


#include "Role/RoleHero.h"
#include "RolePlayerState.h"
#include "Nina.h"
#include "GAS/Common/RPGAbilitySystemComponent.h"

void ARoleHero::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	auto CurPlayerState = GetPlayerState();
	ARolePlayerState* PlayerStateTmp = Cast<ARolePlayerState>(CurPlayerState);
	if (!PlayerStateTmp)
	{
		UE_LOG(LogNina, Error, TEXT("PlayerState is null"));
		return;
	}
	AbilitySystemComponent = Cast<URPGAbilitySystemComponent>(PlayerStateTmp->GetAbilitySystemComponent());
	if (AbilitySystemComponent&&!bAbilitiesInitialized)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AddSlottedGameplayAbilities();
		bAbilitiesInitialized = true;
	}
}

void ARoleHero::UnPossessed()
{
	
}