// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "../JK2PlayerCharacter.h"
#include "JK2Warrior.generated.h"

/**
 * 
 */
UCLASS()
class JK2_API AJK2Warrior : public AJK2PlayerCharacter
{
	GENERATED_BODY()
public:
	AJK2Warrior();
protected:
	virtual void BeginPlay() override;

	//AttackAction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;

	//Montage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage3;

	//Attack Funciton
	void Attack();

	//ComboAction
	UFUNCTION(BlueprintCallable)
	void ComboActionBegin();
	UFUNCTION(BlueprintCallable)
	void DoCombo();
	UFUNCTION(BlueprintCallable)
	void ComboActionEnd();

	//combo == 0 not start combo>=1->Combo Start
	int32 CurrentCombo = 0;
	uint8 IsAttacking : 1;
	uint8 SaveAttacking : 1;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Skill Function
	virtual void SkillQ(const FInputActionValue& value) override;
public:
	//refactoring
	UFUNCTION()
	void CheckWeaponTrace();
};
