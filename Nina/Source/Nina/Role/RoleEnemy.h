// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Role/RoleBase.h"
#include "RoleEnemy.generated.h"

/**
 * 
 */
UCLASS()
class NINA_API ARoleEnemy : public ARoleBase
{
	GENERATED_BODY()
public:
	ARoleEnemy();
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
};
