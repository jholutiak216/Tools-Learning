// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimGraphNode_Base.h"

#define LOCTEXT_NAMESPACE "A3Nodes"


UMyAnimGraphNode_Base::UMyAnimGraphNode_Base(const FObjectInitializer& ObjectInitilizer)
   :Super(ObjectInitilizer)
{

}

FLinearColor UMyAnimGraphNode_Base::GetNodeTitleColor() const
{
   return FLinearColor::Red;
}

FText UMyAnimGraphNode_Base::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
   return LOCTEXT("MyNode", "MyNode");
}

FText UMyAnimGraphNode_Base::GetTooltipText() const
{
   return LOCTEXT("MyNode", "MyNode");
}

FString UMyAnimGraphNode_Base::GetNodeCategory() const
{
   return TEXT("MyNode");
}


#undef LOCTEXT_NAMESPACE