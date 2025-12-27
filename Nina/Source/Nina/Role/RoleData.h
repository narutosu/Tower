// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RoleData.generated.h"

/**
 * 角色的外形与动画。RoleEnemy通过这个数据来初始化敌人外观
 */
UCLASS()
class NINA_API URoleData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	URoleData()
	{
		ItemType = TEXT("RoleData");
	}
	
	/** Type of this item, set in native parent class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = Item)
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = Item)
    TSoftClassPtr<UAnimInstance> AnimInstance;

	/** Overridden to use saved type */
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
