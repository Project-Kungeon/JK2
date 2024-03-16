// Copyright 2024 All Rights Reserved by J&K


#include "JK2PlayerCharacter.h"
#include "JK2.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimMontage.h"

// Sets default values
AJK2PlayerCharacter::AJK2PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	//Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	//Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f,500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.7f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// CameraBoom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 750.f;
	CameraBoom->SetRelativeRotation(FRotator(-20.f, 0.f, 0.f));
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bEnableCameraLag = true;

	// Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//Mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f,0.0f,-88.0f),FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

	IsAttacking = false;
	SaveAttacking = false;
}

// Called when the game starts or when spawned
void AJK2PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AJK2PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Send Packet
	//bool ForceSendPacket = false;	// 상태검사 결과에 따라 패킷 전송할지 말지 판단합니다.

	//if ( LastDesiredInput != DesiredInput )
	//{
	//	// 움직였다면, 패킷 전송을 합니다.
	//	ForceSendPacket = true;
	//	LastDesiredInput = DesiredInput;
	//}

	//if ( DesiredInput == FVector2D::Zero() )
	//	SetMoveState(message::MOVE_STATE_IDLE);
	//else
	//	SetMoveState(message::MOVE_STATE_RUN);

	//// 패킷 전송 주기 계산
	//MovePacketSendTimer -= DeltaTime;

	//if ( MovePacketSendTimer >= 0 || ForceSendPacket )
	//{
	//	MovePacketSendTimer = MOVE_PACKET_SEND_DELAY;
	//	message::C_Move	MovePkt;

	//	{
	//		message::PosInfo* info = MovePkt.mutable_posinfo();
	//		info->CopyFrom(*PlayerInfo);
	//		info->set_yaw(DesiredYaw);
	//		info->set_state(GetMoveState());
	//	}
	//	// TODO : Send Packet should be needed
	//	// Will Test...
	//	SEND_PACKET(message::HEADER::PLAYER_MOVE_REQ, MovePkt);
	//}
}

// Called to bind functionality to input
void AJK2PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AJK2PlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);

}

void AJK2PlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(-LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AJK2PlayerCharacter::Attack()
{
	if ( IsAttacking )
	{
		SaveAttacking = true;
	}
	else
	{
		IsAttacking = true;
		DoCombo();
	}
}

//JJH Assignment
void AJK2PlayerCharacter::SkillQ(const FInputActionValue& value)
{
	UE_LOG(LogTemp, Log, TEXT("This is Parent Class"));
}

void AJK2PlayerCharacter::ComboActionBegin()
{
	if ( SaveAttacking )
	{
		SaveAttacking = false;
		DoCombo();
	}
}

void AJK2PlayerCharacter::DoCombo()
{
}

void AJK2PlayerCharacter::ComboActionEnd()
{
	ensure(CurrentCombo != 0);
	CurrentCombo = 0;
	SaveAttacking = false;
	IsAttacking = false;
}

