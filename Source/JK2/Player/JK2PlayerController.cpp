// Copyright 2024 All Rights Reserved by J&K


#include "JK2PlayerController.h"
#include "GameFramework/Character.h"
#include "JK2/Character/PC/JK2PlayerCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AJK2PlayerController::AJK2PlayerController()
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

void AJK2PlayerController::BeginPlay()
{
	//Cursor off When Play
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
		//Input Priority
	}
}

void AJK2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	if ( EnhancedInputComponent )
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AJK2PlayerController::JumpAct);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AJK2PlayerController::StopJumpingAct);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AJK2PlayerController::MoveAct);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AJK2PlayerController::LookAct);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AJK2PlayerController::AttackAct);
		EnhancedInputComponent->BindAction(QAction, ETriggerEvent::Triggered, this, &AJK2PlayerController::SkillQAct);
	}
}

void AJK2PlayerController::JumpAct()
{
	AJK2PlayerCharacter* ControlledCharacter = Cast<AJK2PlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Jump();
	}
}

void AJK2PlayerController::StopJumpingAct()
{
	AJK2PlayerCharacter* ControlledCharacter = Cast<AJK2PlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->StopJumping();
	}
}

void AJK2PlayerController::LookAct(const FInputActionValue& Value)
{
	AJK2PlayerCharacter* ControlledCharacter = Cast<AJK2PlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Look(Value);
	}
}

void AJK2PlayerController::MoveAct(const FInputActionValue& Value)
{
	AJK2PlayerCharacter* ControlledCharacter = Cast<AJK2PlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Move(Value);
		UE_LOG(LogTemp, Log, TEXT("%s"), *Value.ToString());
	}
}

void AJK2PlayerController::AttackAct()
{
	AJK2PlayerCharacter* ControlledCharacter = Cast<AJK2PlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->Attack();
	}
}

void AJK2PlayerController::SkillQAct(const FInputActionValue& Value)
{
	AJK2PlayerCharacter* ControlledCharacter = Cast<AJK2PlayerCharacter>(GetPawn());
	if ( ControlledCharacter )
	{
		ControlledCharacter->SkillQ(Value);
	}
}
