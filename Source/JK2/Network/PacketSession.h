// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "JK2.h"
#include "CoreMinimal.h"

/**
 * 
 */
class JK2_API PacketSession : public TSharedFromThis<PacketSession>
{
public:
	PacketSession(asio::io_context& io_context) : _socket(io_context)
	{
		memset(_recvBuffer, 0, RecvBufferSize);
	}

	PacketSession(TSharedPtr<asio::io_context> io_context);

	~PacketSession();


	void Run(asio::io_context& io_context);
	void Run(TSharedPtr<asio::io_context> io_context);

	void Connect(std::string host, int port);


	void SendPacket(asio::mutable_buffer& buffer)
	{
		AsyncWrite(buffer);
	}
	// 비동기 읽기 호출
	void AsyncRead();

	TSharedPtr<asio::io_context> GetIoContext()
	{
		return _ioContextRef;
	}


private:
	// 비동기 쓰기 호출
	void AsyncWrite(asio::mutable_buffer& buffer);

	// 접속 컨텐츠 코드
	void OnConnect(const boost::system::error_code& err);

	// 버퍼 송신 컨텐츠 코드
	void OnWrite(const boost::system::error_code& err, size_t size);

	

	// 버퍼 수신 컨텐츠 코드
	void OnRead(const boost::system::error_code& err, size_t size);

	// PacketHeader의 headerCode를 읽고 패킷 클래스 구분
	void HandlePacket(char* ptr, size_t size);

	// 로그인 요청 패킷 전달
	void MakeLoginReq(const int id);

private:
	static const int RecvBufferSize = 1024;
	tcp::socket _socket;
	char _recvBuffer[RecvBufferSize];
	std::string _sendMsg;
	TSharedPtr<class NetworkWorker> NetworkThread;
	TSharedPtr<asio::io_context> _ioContextRef;
};
