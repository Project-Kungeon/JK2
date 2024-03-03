// Copyright 2024 All Rights Reserved by J&K


#include "JK2Archor.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"

AJK2Archor::AJK2Archor()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DefaultMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSparrow/Characters/Heroes/Sparrow/Meshes/Sparrow.Sparrow'"));
	if ( nullptr != DefaultMesh.Object )
	{
		Super::GetMesh()->SetSkeletalMesh(DefaultMesh.Object);
	}
}

void AJK2Archor::BeginPlay()
{
	Super::BeginPlay();
}

void AJK2Archor::Attack()
{
	Super::Attack();
}

void AJK2Archor::ComboActionBegin()
{
	Super::ComboActionBegin();
}

void AJK2Archor::DoCombo()
{
	Super::DoCombo();
	if ( !CurrentCombo )
	{
		CurrentCombo = 1;
		PlayAnimMontage(ComboActionMontage);
	}
}

void AJK2Archor::ComboActionEnd()
{
	Super::ComboActionEnd();
}

void AJK2Archor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ( bWeaponActive )
		CheckWeaponTrace();
}

void AJK2Archor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AJK2Archor::SkillQ(const FInputActionValue& value)
{
	Super::SkillQ(value);
	UE_LOG(LogTemp, Log, TEXT("This is %s"), *this->GetName());
}

void AJK2Archor::CheckWeaponTrace()
{
}
