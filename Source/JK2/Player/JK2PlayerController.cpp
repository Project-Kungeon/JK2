// Copyright 2024 All Rights Reserved by J&K


#include "JK2PlayerController.h"
#include "JK2PlayerController.h"

void AJK2PlayerController::BeginPlay()
{
	//Cursor off When Play
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
