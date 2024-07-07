#pragma once
#include "JK2.h"
#include "Message.pb.h"


// 전역 패킷 핸들러 선언
using PacketHandlerFunc = std::function<bool(PacketSessionRef&, asio::mutable_buffer&, PacketHeader&, int&)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(PacketSessionRef& session, asio::mutable_buffer& buffer, PacketHeader& header, int& offset);

class ClientPacketHandler
{
public:
	static void Init();

	static bool HandlePacket(PacketSessionRef& session, char* ptr, size_t size)
	{
		int offset = 0;
		
		PacketHeader header;
		asio::mutable_buffer buffer = asio::buffer(ptr, size);

		PacketUtil::ParseHeader(buffer, &header, offset);

		return GPacketHandler[header.Code](session, buffer, header, offset);
		
		
	}

private:
	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, PacketSessionRef& session, asio::mutable_buffer& buffer, PacketHeader& header, int& offset)
	{
		PacketType pkt;
		if ( !PacketUtil::Parse(pkt, buffer, header.Length, offset) ) return false;

		return func(session, pkt);
	}

};