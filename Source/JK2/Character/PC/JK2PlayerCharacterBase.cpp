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
#include "PlayerCharacter.h"

AJK2PlayerCharacterBase::AJK2PlayerCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

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
	Super::BeginPlay();
	// Set size for collision capsule
	{
		FVector Location = GetActorLocation();
		FRotator Rotator = GetActorRotation();

		DestInfo->set_x(Location.X);
		DestInfo->set_y(Location.Y);
		DestInfo->set_z(Location.Z);
		DestInfo->set_yaw(Rotator.Yaw);
		DestInfo->set_pitch(Rotator.Pitch);
		DestInfo->set_roll(Rotator.Roll);
		
		SetMoveState(message::MOVE_STATE_IDLE);
	}

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
			//AddMovementInput(GetActorForwardVector());
			FVector vec(DestInfo->x(), DestInfo->y(), DestInfo->z());
			SetActorLocation(vec);

		}
		else if(State == message::MOVE_STATE_IDLE )
		{

			const FRotator YawRotation(0, DestInfo->yaw(), 0);

			const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			AddMovementInput(ForwardDirection, 0);
			AddMovementInput(RightDirection, 0);
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
	return Cast<APlayerCharacter>(this) != nullptr;
}

void AJK2PlayerCharacterBase::SetMoveState(message::MoveState State)
{
	// 기존 상태와 같다면 스킵합니다.
	if ( PlayerInfo->state() == State )
		return;

	PlayerInfo->set_state(State);
}

void AJK2PlayerCharacterBase::SetPlayerInfo(const message::PosInfo& Info)
{
	if ( PlayerInfo->object_id() != 0 )
		return;
	PlayerInfo->CopyFrom(Info);

	// 위치 동기화
	FVector Location(Info.x(), Info.y(), Info.z());
	SetActorLocation(Location);
}

void AJK2PlayerCharacterBase::SetDestInfo(const message::PosInfo& Info)
{
	if ( PlayerInfo->object_id() != 0 )
	{
		assert(PlayerInfo->object_id() == Info.object_id());
	}

	// 위치 동기화
	//FVector TargetLocation(Info.x(), Info.y(), Info.z());
	//FVector MoveDirection = TargetLocation - GetActorLocation();
	//MoveDirection.Normalize();
	//GetCharacterMovement()->AddInputVector(MoveDirection);

	// 위치 정보 갱신
	DestInfo->CopyFrom(Info);
	SetMoveState(Info.state());
}