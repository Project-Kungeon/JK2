// Copyright 2024 All Rights Reserved by J&K


#include "JK2GameInstance.h"

void UJK2GameInstance::Init()
{
	Super::Init();
}

void UJK2GameInstance::ConnectToGameServer()
{
	TSharedPtr<asio::io_context> io_contextRef = MakeShared<asio::io_context>();

	//_sock = new tcp::socket(io_context);
	GameSession = MakeShared<PacketSession>(io_contextRef);

	GameSession->Connect(std::string("127.0.0.1"), 4242);
	GameSession->Run(io_contextRef);
	{
		/*message::C_Login Pkt;
		SEND_PACKET(message::HEADER::LOGIN_REQ, Pkt);*/
	}
}

void UJK2GameInstance::DisconnectFromGameServer()
{
}

void UJK2GameInstance::SendPacket(asio::mutable_buffer& buffer)
{
	GameSession->SendPacket(buffer);
}

void UJK2GameInstance::HandleSpawn(const message::ObjectInfo& info, bool isMyPlayer)
{
	// 세션이 죽은 상태라면 패스
	if (GameSession == nullptr)
		return;

	// 월드를 못 불러오면 패스
	auto* World = GetWorld();
	if (World == nullptr)
		return;

	const uint64 ObjectId = info.object_id();

	// 스폰시키려는 플레이어가 이미 존재하면 패스
	if (Players.Find(ObjectId) != nullptr)
		return;
	
	// 스폰위치 설정(위치는 서버가 정해준다)
	FVector SpawnLocation(info.pos_info().x(), info.pos_info().y(), info.pos_info().z());

	// 만약 내 플레이어라면, 필요한 컴포넌트를 달아준다.
	if (isMyPlayer)
	{
		auto* PC = UGameplayStatics::GetPlayerController(this, 0);
		auto* Player = Cast<AJK2PlayerCharacterBase>(PC->GetPawn());
		if (Player == nullptr)
			return;

		Player->SetPlayerInfo(info.pos_info());

		MyPlayer = Player;
		Players.Add(info.object_id(), Player);

	}
	else
	{
		auto* Player = Cast<AJK2PlayerCharacterBase>(World->SpawnActor(OtherPlayerClass, &SpawnLocation));
		Player->SetPlayerInfo(info.pos_info());
		Players.Add(info.object_id(), Player);
	}
}

// 내가 아닌 다른 개체가 스폰되었을 때 동기화해주는 함수
void UJK2GameInstance::HandleSpawn(message::S_Spawn& SpawnPkt)
{
	for (auto& player : SpawnPkt.players())
	{
		HandleSpawn(player, false);
	}
}

void UJK2GameInstance::HandleSpawn(message::S_EnterRoom& EnterRoomPkt)
{
	HandleSpawn(EnterRoomPkt.player(), true);
}
