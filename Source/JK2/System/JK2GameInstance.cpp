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
		message::C_Login Pkt;
		SEND_PACKET(message::HEADER::LOGIN_REQ, Pkt);
	}
}

void UJK2GameInstance::DisconnectFromGameServer()
{
}

void UJK2GameInstance::SendPacket(asio::mutable_buffer& buffer)
{
	GameSession->SendPacket(buffer);
}