#include "GSRoleAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UGSRoleAttributeSet::UGSRoleAttributeSet()
{
	
}

void UGSRoleAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UGSRoleAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UGSRoleAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, HP, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, MaxHP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, HPRegenRate, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, AttackRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, CriticalProb, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, CriticalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, Resistance, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGSRoleAttributeSet, Gold, COND_None, REPNOTIFY_Always);
}

void UGSRoleAttributeSet::OnRep_HP(const FGameplayAttributeData& OldHP)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, HP, OldHP);
}

void UGSRoleAttributeSet::OnRep_MaxHP(const FGameplayAttributeData& OldMaxHP)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, MaxHP, OldMaxHP);
}

void UGSRoleAttributeSet::OnRep_HPRegenRate(const FGameplayAttributeData& OldHPRegenRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, HPRegenRate, OldHPRegenRate);
}

void UGSRoleAttributeSet::OnRep_Attack(const FGameplayAttributeData& OldAttack)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, Attack, OldAttack);
}

void UGSRoleAttributeSet::OnRep_AttackRate(const FGameplayAttributeData& OldAttackRate)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, AttackRate, OldAttackRate);
}

void UGSRoleAttributeSet::OnRep_CriticalProb(const FGameplayAttributeData& OldCriticalProb)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, CriticalProb, OldCriticalProb);
}

void UGSRoleAttributeSet::OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, CriticalDamage, OldCriticalDamage);
}

void UGSRoleAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, Armor, OldArmor);
}

void UGSRoleAttributeSet::OnRep_Resistance(const FGameplayAttributeData& OldResistance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, Resistance, OldResistance);
}

void UGSRoleAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, Level, OldLevel);
}

void UGSRoleAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, Speed, OldSpeed);
}

void UGSRoleAttributeSet::OnRep_Gold(const FGameplayAttributeData& OldGold)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGSRoleAttributeSet, Gold, OldGold);
}
