// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PacketSession.h"
#include "JK2.h"
#include "../Character/PC/JK2PlayerCharacterBase.h"
#include "../Character/PC/PlayerCharacter.h"
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

	// 플레이어 소환(내 플레이어일 경우, Controller 부착)
	void HandleSpawn(const message::ObjectInfo& info, bool isMyPlayer);
	// 서버로부터 스폰 요청이 들어올 경우
	void HandleSpawn(message::S_Spawn& SpawnPkt);
	// 게임 접속 후, 내 플레이어 스폰
	void HandleSpawn(message::S_EnterRoom& EnterRoomPkt);

	void HandleMove(const message::S_Move& movePkt);
	void HandleDespawn(const message::S_Despawn& despawnPkt);

private:
	PacketSessionRef GameSession;

public:
	UPROPERTY(EditAnywhere);
	TSubclassOf<AJK2PlayerCharacterBase> OtherPlayerClass;

	TMap<uint64, AJK2PlayerCharacterBase*> Players;
	AJK2PlayerCharacterBase* MyPlayer;
};
