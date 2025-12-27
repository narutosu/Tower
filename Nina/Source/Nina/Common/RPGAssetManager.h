#pragma once

#include "Nina.h"
#include "Engine/AssetManager.h"
#include "RPGAssetManager.generated.h"

UCLASS()
class URPGAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URPGAssetManager() {}
	virtual void StartInitialLoading() override;

	/** Static types for items */
	static const FPrimaryAssetType	PotionItemType;
	static const FPrimaryAssetType	SkillItemType;
	static const FPrimaryAssetType	TokenItemType;
	static const FPrimaryAssetType	WeaponItemType;

	/** Returns the current AssetManager object */
	UFUNCTION(BlueprintCallable)
	static URPGAssetManager* Get();

	UFUNCTION(BlueprintCallable)
	class UPrimaryDataAsset* ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning = true);
};

