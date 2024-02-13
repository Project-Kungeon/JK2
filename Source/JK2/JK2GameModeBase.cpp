// Copyright Epic Games, Inc. All Rights Reserved.


#include "JK2GameModeBase.h"

AJK2GameModeBase::AJK2GameModeBase()
{
	//Set DefaultPawnClass
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("Blueprint'/Game/Character/PC/BP_JK2PlayerCharacter.BP_JK2PlayerCharacter_C'"));
	if (nullptr != DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}
	//Set PlayerControllerClass
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/JK2.JK2PlayerController"));
	if (nullptr != PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
}
