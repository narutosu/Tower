// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Common/RPGTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "GAS/Attribute/GSRoleAttributeSet.h"
#include "RoleBase.generated.h"


// struct FGameplayAbilitySpecHandle;
UCLASS()
class NINA_API ARoleBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARoleBase();

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void OnRep_Controller() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Implement IAbilitySystemInterface
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UGSRoleAttributeSet* GetRoleAttributeSet() const;
protected:
	UPROPERTY()
	class URPGAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UGSRoleAttributeSet* RoleAttributeSet;

	/** The level of this character, should not be modified directly once it has already spawned */
	UPROPERTY(EditAnywhere, Replicated, Category = Abilities)
	int32 CharacterLevel;

	UPROPERTY(EditAnywhere, Category = Abilities)
	TArray<FItemData> DefaultItemDatas;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FItemData, FGameplayAbilitySpecHandle> SlottedAbilities;

	UPROPERTY()
	int32 bAbilitiesInitialized;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActivateAbilitiesWithSlotNum(int32 SlotNumber, bool bAllowRemoteActivation = true);
	
	/** Adds slotted item abilities if needed */
	void AddSlottedGameplayAbilities();

	/** Remove slotted gameplay abilities, if force is false it only removes invalid ones */
	void RemoveSlottedGameplayAbilities(bool bRemoveAll);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns the character level that is passed to the ability system */
	UFUNCTION(BlueprintCallable)
	virtual int32 GetCharacterLevel() const;

	/** Modifies the character level, this may change abilities. Returns true on success */
	UFUNCTION(BlueprintCallable)
	virtual bool SetCharacterLevel(int32 NewLevel);

	UFUNCTION(BlueprintCallable)
    void StopMove();

public:
	//属性获取
	UFUNCTION(BlueprintCallable)
	virtual float GetSpeed() const;
	
	//属性回调
	virtual void HandleHealthChanged(float NewValue, const struct FGameplayTagContainer& EventTags);
	virtual void HandleManaChanged(float NewValue, const struct FGameplayTagContainer& EventTags);
	virtual void HandleMoveSpeedChanged(float NewValue, const struct FGameplayTagContainer& EventTags);

public:
	UFUNCTION(BlueprintCallable)
	virtual float GetAttackRate() const;
};
