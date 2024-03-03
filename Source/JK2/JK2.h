// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio/buffer.hpp>
#include "Message.pb.h"
#include "Packet.h"

class PacketSession;

using namespace boost;
using boost::asio::ip::tcp;

#define USING_SHARED_PTR(name)	using name##Ref = TSharedPtr<class name>;
USING_SHARED_PTR(PacketSession);

#include "./PacketHandler/ClientPacketHandler.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"