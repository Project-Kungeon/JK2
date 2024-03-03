// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Message.pb.h"
#include "JK2PlayerCharacter.h"
#include "JK2PlayerCharacterBase.generated.h"

UCLASS()
class JK2_API AJK2PlayerCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJK2PlayerCharacterBase();
	virtual ~AJK2PlayerCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// is this character my player?
	bool isMyPlayer();

	message::MoveState GetMoveState() { return PlayerInfo->state(); }
	void SetMoveState(message::MoveState State);

	// Getter, Setter
public:
	void SetPlayerInfo(message::PosInfo& Info);
	void SetDestInfo(message::PosInfo& Info);
	message::PosInfo* GetPlayerInfo() { return PlayerInfo; }

protected:
	class message::PosInfo* PlayerInfo;		// 플레이어 정보
	class message::PosInfo* DestInfo;		// 목적지 정보 -> 이동 동기화

};
