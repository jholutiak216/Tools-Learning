// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "MyAnimNode_Base.generated.h"

/**
 * 
 */
USTRUCT()
struct SIMPLESHOOTER_API FMyAnimNode_Base : public FAnimNode_Base
{
	GENERATED_BODY()

	FMyAnimNode_Base();
	
	UPROPERTY(EditAnywhere, Category=Links)
	FPoseLink BasePose;

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	//virtual void EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
};
