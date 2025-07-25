#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GSRoleAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class UGSRoleAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UGSRoleAttributeSet();

	/**
     * 血量
     */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_HP)
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, HP)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHP)
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, MaxHP)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_HPRegenRate)
	FGameplayAttributeData HPRegenRate;
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, HPRegenRate)
	
	/**
	 * 攻防
     */
    UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_Attack)
    FGameplayAttributeData Attack;
    ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, Attack)

	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_AttackRate)
    FGameplayAttributeData AttackRate;//攻击频率
    ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, AttackRate)

	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_CriticalProb)
	FGameplayAttributeData CriticalProb;//暴击率
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, CriticalProb)

	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_CriticalDamage)
    FGameplayAttributeData CriticalDamage;
    ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, CriticalDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_Armor)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, Armor)

	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_Resistance)
	FGameplayAttributeData Resistance;//状态抗性
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, Resistance)

	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_Level)
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, Level)

	/**
     * 其它
     */
    UPROPERTY(BlueprintReadOnly, Category = "other", ReplicatedUsing = OnRep_Speed)
    FGameplayAttributeData Speed;
    ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, Speed)

	UPROPERTY(BlueprintReadOnly, Category = "other", ReplicatedUsing = OnRep_Gold)
	FGameplayAttributeData Gold;
	ATTRIBUTE_ACCESSORS(UGSRoleAttributeSet, Gold)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
protected:
	UFUNCTION()
	virtual void OnRep_HP(const FGameplayAttributeData& OldHP);

	UFUNCTION()
    virtual void OnRep_MaxHP(const FGameplayAttributeData& OldMaxHP);

	UFUNCTION()
    virtual void OnRep_HPRegenRate(const FGameplayAttributeData& OldHPRegenRate);

	UFUNCTION()
    virtual void OnRep_Attack(const FGameplayAttributeData& OldAttack);

	UFUNCTION()
    virtual void OnRep_AttackRate(const FGameplayAttributeData& OldAttackRate);

	UFUNCTION()
    virtual void OnRep_CriticalProb(const FGameplayAttributeData& OldCriticalProb);

	UFUNCTION()
    virtual void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage);

	UFUNCTION()
    virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);

	UFUNCTION()
    virtual void OnRep_Resistance(const FGameplayAttributeData& OldResistance);

	UFUNCTION()
    virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

	UFUNCTION()
    virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);

	UFUNCTION()
    virtual void OnRep_Gold(const FGameplayAttributeData& OldGold);
};