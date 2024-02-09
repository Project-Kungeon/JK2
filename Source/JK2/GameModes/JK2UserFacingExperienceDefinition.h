// Copyright 2024 All Rights Reserved by J&K.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "JK2UserFacingExperienceDefinition.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class JK2_API UJK2UserFacingExperienceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	/** The specific map to load */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Experience, meta = (AllowedTypes = "Map"))
	FPrimaryAssetId MapID;

	/** The gameplay experience to load */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Experience, meta = (AllowedTypes = "LyraExperienceDefinition"))
	FPrimaryAssetId ExperienceID;


};