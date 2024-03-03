// Copyright 2024 All Rights Reserved by J&K

#include "Character/PC/JK2PlayerCharacterBase.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
AJK2PlayerCharacterBase::AJK2PlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AJK2PlayerCharacterBase::~AJK2PlayerCharacterBase()
{
	delete PlayerInfo;
	delete DestInfo;
	PlayerInfo = nullptr;
	DestInfo = nullptr;
}

// Called when the game starts or when spawned
void AJK2PlayerCharacterBase::BeginPlay()
{
	//Super::BeginPlay();
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->bRunPhysicsWithNoController = true;

	PlayerInfo = new message::PosInfo();
	DestInfo = new message::PosInfo();
	
}

// Called every frame
void AJK2PlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{
		FVector Location = GetActorLocation();
		PlayerInfo->set_x(Location.X);
		PlayerInfo->set_y(Location.Y);
		PlayerInfo->set_z(Location.Z);
		PlayerInfo->set_yaw(GetControlRotation().Yaw);
	}

	if ( isMyPlayer() == false )
	{
		const message::MoveState State = GetMoveState();

		if ( State == message::MOVE_STATE_RUN )	// 뛰는 중이라면
		{
			SetActorRotation(FRotator(0, DestInfo->yaw(), 0));
			AddMovementInput(GetActorForwardVector());
			
		}
		else
		{

		}

	}
}

// Called to bind functionality to input
void AJK2PlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AJK2PlayerCharacterBase::isMyPlayer()
{
	return Cast<AJK2PlayerCharacter>(this) != nullptr;
}

void AJK2PlayerCharacterBase::SetMoveState(message::MoveState State)
{
	// 기존 상태와 같다면 스킵합니다.
	if ( PlayerInfo->state() == State )
		return;

	PlayerInfo->set_state(State);
}

void AJK2PlayerCharacterBase::SetPlayerInfo(message::PosInfo& Info)
{
	if ( PlayerInfo->object_id() != 0 )
		return;
	PlayerInfo->CopyFrom(Info);

	// 위치 동기화
	FVector Location(Info.x(), Info.y(), Info.z());
	SetActorLocation(Location);
}

void AJK2PlayerCharacterBase::SetDestInfo(message::PosInfo& Info)
{
	if ( PlayerInfo->object_id() != 0 )
		return;
	DestInfo->CopyFrom(Info);
	SetMoveState(Info.state());
}

