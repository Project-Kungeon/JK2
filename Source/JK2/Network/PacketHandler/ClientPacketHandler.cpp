#include "ClientPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(PacketSessionRef& session, asio::mutable_buffer& buffer, int& offset)
{
    return false;
}

void ClientPacketHandler::Init()
{
    for ( int i = 0; i < UINT16_MAX; i++ )
        GPacketHandler[i] = Handle_INVALID;

    GPacketHandler[message::HEADER::LOGIN_RES] = [](PacketSessionRef& session, asio::mutable_buffer& buffer, int& offset)
    {
        return HandlePacket<message::S_Login>(LobbyPacketHandler::Handle_S_Login, session, buffer, offset);
    };

}