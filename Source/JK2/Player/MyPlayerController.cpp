// Copyright 2024 All Rights Reserved by J&K


#include "Player/MyPlayerController.h"
#include "GameFramework/Character.h"
#include "JK2/Character/PC/PlayerCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController()
{
	//InputMappingContext & InputAction
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextRef(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_JK2.IMC_JK2'"));
	if ( nullptr != InputMappingContextRef.Object )
	{
		DefaultMappingContext = InputMappingContextRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Move.IA_Move'"));
	if ( nullptr != InputActionMoveRef.Object )
	{
		MoveAction = InputActionMoveRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Jump.IA_Jump'"));
	if ( nullptr != InputActionJumpRef.Object )
	{
		JumpAction = InputActionJumpRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Look.IA_Look'"));
	if ( nullptr != InputActionLookRef.Object )
	{
		LookAction = InputActionLookRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionAttackRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Attack.IA_Attack'"));
	if ( nullptr != InputActionAttackRef.Object )
	{
		AttackAction = InputActionAttackRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionSkillQRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Skill_Q.IA_Skill_Q'"));
	if ( nullptr != InputActionSkillQRef.Object )
	{
		QAction = InputActionSkillQRef.Object;
	}
}

void AMyPlayerController::BeginPlay()
{
	//Cursor off When Play
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if ( Subsystem )
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
		//Input Priority
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	if ( EnhancedInputComponent )
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyPlayerController::JumpAct);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyPlayerController::StopJumpingAct);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::MoveAct);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPlayerController::LookAct);
	}
}

void AMyPlayerController::JumpAct()
{
	APlayerCharacter* ControlledCharacter = Cast<APlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Jump();
	}
}

void AMyPlayerController::StopJumpingAct()
{
	APlayerCharacter* ControlledCharacter = Cast<APlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->StopJumping();
	}
}

void AMyPlayerController::LookAct(const FInputActionValue& Value)
{
	APlayerCharacter* ControlledCharacter = Cast<APlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Look(Value);
	}
}

void AMyPlayerController::MoveAct(const FInputActionValue& Value)
{
	APlayerCharacter* ControlledCharacter = Cast<APlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Move(Value);
	}
}

