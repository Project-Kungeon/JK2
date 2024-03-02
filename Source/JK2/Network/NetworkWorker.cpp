// Copyright 2024 All Rights Reserved by J&K


#include "Network/NetworkWorker.h"

NetworkWorker::NetworkWorker(TSharedPtr<asio::io_context> io_context, TSharedPtr<PacketSession> Session)
	: io_contextRef(io_context), SessionRef(Session)
{
	Thread = FRunnableThread::Create(this, TEXT("NetworkWorker"));
}

NetworkWorker::~NetworkWorker()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("~NetworkWorker()")));
}

bool NetworkWorker::Init()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Network Thread Init")));

	return true;
}

uint32 NetworkWorker::Run()
{
	try
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Network Thread Running")));
		io_contextRef->run();
		;		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Network Thread Done")));

	}
	catch ( const std::exception& e )
	{
		FString formattedString = FString::Printf(TEXT("%s"), *FString(UTF8_TO_TCHAR(e.what())));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *formattedString);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, formattedString);
	}
	return 0;
}

void NetworkWorker::Exit()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Network Thread Exited")));
}

void NetworkWorker::Stop()
{

}

void NetworkWorker::Destroy()
{
	Running = false;
}
