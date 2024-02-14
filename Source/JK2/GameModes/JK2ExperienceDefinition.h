// Copyright 2024 All Rights Reserved by J&K.
#pragma once

#include "Engine/DataAsset.h"
#include "JK2ExperienceDefinition.generated.h"

/** forward declaration */
class UJK2PawnData;

UCLASS(BlueprintType)
class UJK2ExperienceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UJK2ExperienceDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	* member variables
	*/
	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TObjectPtr<UJK2PawnData> DefaultPawnData;

	/**
	* 해당 property는 단순히 마킹 및 기억용으로 남겨둔다
	* - 게임 모드에 따른 GameFeature plugin을 로딩하는데 이에 대한 연결고리라고 생각하면 된다
	* - 후일 ShooterCore 관련 Plugin 작업할 경우, 진행하게 될 예정이다
	*/
	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TArray<FString> GameFeatureToEnable;
};