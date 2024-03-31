#pragma once
#include "JK2.h"
#include "Message.pb.h"


// 전역 패킷 핸들러 선언
using PacketHandlerFunc = std::function<bool(PacketSessionRef&, asio::mutable_buffer&, int&)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(PacketSessionRef& session, asio::mutable_buffer& buffer, int& offset);

class ClientPacketHandler
{
public:
	static void Init();

	static bool HandlePacket(PacketSessionRef& session, char* ptr, size_t size)
	{
		PacketHeader header;
		asio::mutable_buffer buffer = asio::buffer(ptr, size);
		int offset = 0;
		PacketUtil::ParseHeader(buffer, &header, offset);

		return GPacketHandler[header.Code](session, buffer, offset);
	}

private:
	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, PacketSessionRef& session, asio::mutable_buffer& buffer, int& offset)
	{
		PacketType pkt;
		if ( !PacketUtil::Parse(pkt, buffer, buffer.size() - offset, offset) ) return false;

		return func(session, pkt);
	}

};