// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimNode_Base.h"

FMyAnimNode_Base::FMyAnimNode_Base()
{

}

void FMyAnimNode_Base::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
   BasePose.Initialize(Context);
}

void FMyAnimNode_Base::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
   BasePose.CacheBones(Context);
}

void FMyAnimNode_Base::Update_AnyThread(const FAnimationUpdateContext& Context)
{
   GetEvaluateGraphExposedInputs().Execute(Context);
   BasePose.Update(Context);
}

void FMyAnimNode_Base::Evaluate_AnyThread(FPoseContext& Output)
{
   BasePose.Evaluate(Output);
}

void FMyAnimNode_Base::GatherDebugData(FNodeDebugData& DebugData)
{
   FString DebugLine = DebugData.GetNodeName(this);
   DebugData.AddDebugItem(DebugLine);
   BasePose.GatherDebugData(DebugData);
}
