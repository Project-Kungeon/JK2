// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "JK2PlayerCharacterBase.h"
#include "JK2PlayerCharacter.generated.h"

UCLASS()
class JK2_API AJK2PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJK2PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Move and Look Function
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	//Attack Function
	virtual void Attack();
	//Skill Function
	virtual void SkillQ(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
		virtual void ComboActionBegin();
	UFUNCTION(BlueprintCallable)
		virtual void DoCombo();
	UFUNCTION(BlueprintCallable)
		virtual void ComboActionEnd();

	//combo == 0 not start combo>=1->Combo Start
	int32 CurrentCombo = 0;
	uint8 IsAttacking : 1;
	uint8 SaveAttacking : 1;

protected:
	UPROPERTY(EditAnywhere, Category = "Camera")
		TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere, Category = "Camera")
		TObjectPtr<class UCameraComponent> FollowCamera;

	//Move&Look Function

	//Skill Function

public:
	UPROPERTY(BlueprintReadWrite)
		bool bWeaponActive;

	UPROPERTY()
		TSet<AActor*> WeaponAttackTargets;


protected:
	// Relate Network...

	// 패킷 전송 주기(Pakcet Sending Delay)
	const float MOVE_PACKET_SEND_DELAY = 0.2f;
	float MovePacketSendTimer = MOVE_PACKET_SEND_DELAY;

	// Position Cache (이 값으로 이동 여부 판단)
	FVector2D DesiredInput;
	FVector DesiredMoveDirection;
	float DesiredYaw;

	// Dirty Flag Test (이동 상태 검사)
	FVector2D LastDesiredInput;
};