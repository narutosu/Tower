// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "RolePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class NINA_API ARolePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ARolePlayerState();

	// Implement IAbilitySystemInterface
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UGSRoleAttributeSet* GetRoleAttributeSet() const;
protected:
	UPROPERTY()
	class UGSAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UGSRoleAttributeSet* RoleAttributeSet;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
