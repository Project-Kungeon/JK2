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

	//Montage, 클래스들은 각자 기본공격 몽타주 갯수가 다르다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage3;

	//Attack Funciton
	virtual void Attack() override;

	//ComboAction
	virtual void ComboActionBegin() override;
	virtual void DoCombo() override;
	virtual void ComboActionEnd() override;

	
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
