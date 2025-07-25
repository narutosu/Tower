#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GSAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class UGSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	UGSAbilitySystemComponent();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
