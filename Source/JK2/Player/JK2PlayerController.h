// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "JK2PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class JK2_API AJK2PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AJK2PlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	//InputMappingContext
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	//JumpAction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	//MoveAction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;

	//LookAction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;

	//AttackAction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;

	//SkillQAction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> QAction;

	void JumpAct();
	void StopJumpingAct();
	void LookAct(const FInputActionValue& Value);
	void MoveAct(const FInputActionValue& Value);
	void AttackAct();
	void SkillQAct(const FInputActionValue& Value);
	
};
