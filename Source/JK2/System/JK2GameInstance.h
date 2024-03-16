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

	UFUNCTION(BlueprintCallable)
		void ConnectToGameServer();

	UFUNCTION(BlueprintCallable)
		void DisconnectFromGameServer();

	void SendPacket(asio::mutable_buffer& buffer);


private:
	PacketSessionRef GameSession;
};
