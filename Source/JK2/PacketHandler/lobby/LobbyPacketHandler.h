#pragma once
#include "../../JK2.h"

class LobbyPacketHandler
{
public:
	static bool Handle_S_Login(PacketSessionRef& session, message::S_Login& pkt);
};

