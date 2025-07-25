// Fill out your copyright notice in the Description page of Project Settings.

#include "Role/RoleBase.h"
#include "GAS/Component/GSAbilitySystemComponent.h"
#include "GAS/Attribute/GSRoleAttributeSet.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ARoleBase::ARoleBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARoleBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ARoleBase::UnPossessed()
{
	
}

void ARoleBase::OnRep_Controller()
{
	Super::OnRep_Controller();
}

void ARoleBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARoleBase, CharacterLevel);
}

UAbilitySystemComponent* ARoleBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UGSRoleAttributeSet* ARoleBase::GetRoleAttributeSet() const
{
	return RoleAttributeSet;
}

// Called when the game starts or when spawned
void ARoleBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARoleBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 ARoleBase::GetCharacterLevel() const
{
	return CharacterLevel;
}

bool ARoleBase::SetCharacterLevel(int32 NewLevel)
{
	if (CharacterLevel != NewLevel && NewLevel > 0)
	{
		// Our level changed so we need to refresh abilities
		// RemoveStartupGameplayAbilities();
		CharacterLevel = NewLevel;
		// AddStartupGameplayAbilities();

		return true;
	}
	return false;
}
