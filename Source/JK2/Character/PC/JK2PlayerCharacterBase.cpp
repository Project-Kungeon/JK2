// Copyright 2024 All Rights Reserved by J&K


#include "Character/PC/JK2PlayerCharacterBase.h"

// Sets default values
AJK2PlayerCharacterBase::AJK2PlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJK2PlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJK2PlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJK2PlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

