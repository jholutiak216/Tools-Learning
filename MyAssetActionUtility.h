// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "MyAssetActionUtility.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMyAssetActionUtility : public UAssetActionUtility
{
	GENERATED_BODY()

public:
	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase);

	UFUNCTION(CallInEditor)
	void CheckPowerOfTwo();

private:
	bool IsPowerofTwo(int32 NumberToCheck);

	void PrintToScreen(FString Message, FColor Color);

	void GiveFeedback(FString Method, uint32 Counter);
};
