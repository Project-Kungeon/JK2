// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "../JK2PlayerCharacter.h"
#include "JK2Archor.generated.h"

/**
 * 
 */
UCLASS()
class JK2_API AJK2Archor : public AJK2PlayerCharacter
{
	GENERATED_BODY()
public:
	AJK2Archor();
protected:
	virtual void BeginPlay() override;

	//Montage, 클래스들은 각자 기본공격 몽타주 갯수가 다르다.
	//Archor는 활을 쏘는 모션 하나.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	//Attack Funciton
	virtual void Attack() override;

	void Shoot();
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

	
	UFUNCTION()
	void CheckWeaponTrace();
};
