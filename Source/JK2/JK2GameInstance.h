// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PacketSession.h"
#include "JK2.h"
#include "JK2GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class JK2_API UJK2GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	void ConnectToGameServer();
	void DisconnectFromGameServer();


private:
	PacketSessionRef GameSession;


};
