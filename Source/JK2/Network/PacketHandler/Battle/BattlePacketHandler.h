#pragma once
#include "JK2.h"

class BattlePacketHandler
{
public:
	static bool Handle_S_Attack(PacketSessionRef& session, message::S_Attack& pkt);
};