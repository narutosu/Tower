// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Common/RPGTypes.h"
#include "ItemManager.generated.h"

/**
 * 
 */
UCLASS()
class NINA_API UItemManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = Inventory)
	TMap<FRPGItemSlot, URPGItem*> SkillSlottedItems;

	UPROPERTY(VisibleAnywhere, Category = Inventory)
	TMap<FRPGItemSlot, URPGItem*> EquipSlottedItems;

	int32 MaxSkillSlots = 10;

	int32 MaxEquipSlots = 10;
		
public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
};
