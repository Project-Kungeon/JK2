// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JK2PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class JK2_API AJK2PlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	
};
