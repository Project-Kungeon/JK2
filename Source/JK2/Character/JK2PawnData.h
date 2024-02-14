// Copyright 2024 All Rights Reserved by J&K.
#pragma once

#include "Engine/DataAsset.h"
#include "JK2PawnData.generated.h"


UCLASS()
class UJK2PawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UJK2PawnData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** 단순히 형태만 만들어놓기 */
};