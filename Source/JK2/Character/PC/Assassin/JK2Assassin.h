// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "../JK2PlayerCharacter.h"
#include "JK2Assassin.generated.h"

/**
 * 
 */
UCLASS()
class JK2_API AJK2Assassin : public AJK2PlayerCharacter
{
	GENERATED_BODY()
public:
	AJK2Assassin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION()
	void CheckWeaponTrace();
};
