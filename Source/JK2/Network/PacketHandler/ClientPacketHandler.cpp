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
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("S_Login Handle")));
        return HandlePacket<message::S_Login>(LobbyPacketHandler::Handle_S_Login, session, buffer, offset);
    };
    GPacketHandler[message::HEADER::ENTER_ROOM_RES] = [](PacketSessionRef& session, asio::mutable_buffer& buffer, int& offset)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("S_EnterRoom Handle")));
        return HandlePacket<message::S_EnterRoom>(RoomPacketHandler::Handle_S_EnterRoom, session, buffer, offset);
    };
    GPacketHandler[message::HEADER::PLAYER_SPAWN_RES] = [](PacketSessionRef& session, asio::mutable_buffer& buffer, int& offset)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("S_Spawn Handle")));
        return HandlePacket<message::S_Spawn>(RoomPacketHandler::Handle_S_Spawn, session, buffer, offset);
    };

}