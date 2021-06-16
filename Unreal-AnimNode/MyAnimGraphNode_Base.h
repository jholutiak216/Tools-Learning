// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "MyAnimNode_Base.h"
#include "MyAnimGraphNode_Base.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMyAnimGraphNode_Base : public UAnimGraphNode_Base
{
	GENERATED_BODY()

	UMyAnimGraphNode_Base(const FObjectInitializer& ObjectInitilizer);

	UPROPERTY(EditAnywhere, Category=Settings)
	FMyAnimNode_Base Node;

	//Graph Node interface
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;

	virtual FString GetNodeCategory() const override;
	
};
