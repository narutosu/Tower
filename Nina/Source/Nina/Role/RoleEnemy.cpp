// Fill out your copyright notice in the Description page of Project Settings.


#include "Role/RoleEnemy.h"
#include "GAS/Common/RPGAbilitySystemComponent.h"

ARoleEnemy::ARoleEnemy()
{
	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Mixed mode means we only are replicated the GEs to ourself, not the GEs to simulated proxies. If another GDPlayerState (Hero) receives a GE,
	// we won't be told about it by the Server. Attributes, GameplayTags, and GameplayCues will still replicate to us.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void ARoleEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// AbilitySystemComponent = NewObject<URPGAbilitySystemComponent>(GetWorld(), URPGAbilitySystemComponent::StaticClass());
	// AbilitySystemComponent->SetIsReplicated(true);
	// AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	if (AbilitySystemComponent&&!bAbilitiesInitialized)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AddSlottedGameplayAbilities();
		bAbilitiesInitialized = true;
	}
}

void ARoleEnemy::UnPossessed()
{
	
}