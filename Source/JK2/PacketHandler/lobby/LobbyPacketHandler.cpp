#include "LobbyPacketHandler.h"

bool LobbyPacketHandler::Handle_S_Login(PacketSessionRef& session, message::S_Login& pkt)
{

    for ( int32 i = 0; i < pkt.players_size(); i++ )
    {
        // TODO 모든 플레이어에 대해 전처리
        const message::ObjectInfo& Player = pkt.players(i);
    }

    // 방 입장 요청
    message::C_EnterRoom EnterRoomPkt;
    EnterRoomPkt.set_playerindex(0);

    SEND_PACKET(message::HEADER::ENTER_ROOM_REQ, EnterRoomPkt);
    return true;
}
