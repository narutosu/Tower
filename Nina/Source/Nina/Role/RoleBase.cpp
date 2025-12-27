// Fill out your copyright notice in the Description page of Project Settings.

#include "Role/RoleBase.h"
#include "GAS/Common/RPGAbilitySystemComponent.h"
#include "GAS/Attribute/GSRoleAttributeSet.h"
#include "GAS/Common/RPGGameplayAbility.h"
#include "Common/RPGAssetManager.h"
#include "Common/RPGTypes.h"
#include "Items/RPGItem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ARoleBase::ARoleBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	//AbilitySystemComponent->SetIsReplicated(true);

	// Create the attribute set, this replicates by default
	RoleAttributeSet = CreateDefaultSubobject<UGSRoleAttributeSet>(TEXT("AttributeSet"));
	
	CharacterLevel = 1;
	bAbilitiesInitialized = false;
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

	ActivateAbilitiesWithSlotNum(0);
	
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

void ARoleBase::StopMove()
{
	GetMovementComponent()->StopMovementImmediately();
}

float ARoleBase::GetSpeed() const
{
	return RoleAttributeSet->GetSpeed();
}

void ARoleBase::HandleHealthChanged(float NewValue, const struct FGameplayTagContainer& EventTags)
{
	// We only call the BP callback if this is not the initial ability setup
	if (bAbilitiesInitialized)
	{
	}
}

void ARoleBase::HandleManaChanged(float NewValue, const struct FGameplayTagContainer& EventTags)
{
	if (bAbilitiesInitialized)
	{
	}
}

void ARoleBase::HandleMoveSpeedChanged(float NewValue, const struct FGameplayTagContainer& EventTags)
{
	// Update the character movement's walk speed
	GetCharacterMovement()->MaxWalkSpeed = GetSpeed();
}

bool ARoleBase::ActivateAbilitiesWithSlotNum(int32 SlotNumber, bool bAllowRemoteActivation)
{
	for (TPair<FItemData, FGameplayAbilitySpecHandle>& ExistingPair : SlottedAbilities)
	{
		if(ExistingPair.Key.SlotNumber == SlotNumber&&ExistingPair.Value.IsValid())
		{
			if (AbilitySystemComponent)
			{
				return AbilitySystemComponent->TryActivateAbility(ExistingPair.Value,bAllowRemoteActivation);
			}
		}
	}
	return false;
}

void ARoleBase::AddSlottedGameplayAbilities()
{
	// Now add abilities if needed
	for (FItemData& ItemData : DefaultItemDatas)
	{
		if(ItemData.ItemAssetId.PrimaryAssetType == URPGAssetManager::SkillItemType)
		{
			ItemData.RPGItem = Cast<URPGItem>(URPGAssetManager::Get()->ForceLoadItem(ItemData.ItemAssetId));
		}
		FGameplayAbilitySpecHandle& SpecHandle = SlottedAbilities.FindOrAdd(ItemData);
	
		if (!SpecHandle.IsValid())
		{
			TSubclassOf<URPGGameplayAbility> AbilityClass = ItemData.RPGItem->GrantedAbility;
			FGameplayAbilitySpec Spec(AbilityClass, GetCharacterLevel(), INDEX_NONE, this);
			SpecHandle = AbilitySystemComponent->GiveAbility(Spec);
		}
	}
}

void ARoleBase::RemoveSlottedGameplayAbilities(bool bRemoveAll)
{
	for (TPair<FItemData, FGameplayAbilitySpecHandle>& ExistingPair : SlottedAbilities)
	{
		FGameplayAbilitySpec* FoundSpec = AbilitySystemComponent->FindAbilitySpecFromHandle(ExistingPair.Value);
		bool bShouldRemove = bRemoveAll || !FoundSpec;
		if (bShouldRemove)
		{	
			if (FoundSpec)
			{
				// Need to remove registered ability
				AbilitySystemComponent->ClearAbility(ExistingPair.Value);
			}
	
			// Make sure handle is cleared even if ability wasn't found
			ExistingPair.Value = FGameplayAbilitySpecHandle();
		}
	}
}

float ARoleBase::GetAttackRate() const
{
	return RoleAttributeSet->GetAttackSpeed();
}
