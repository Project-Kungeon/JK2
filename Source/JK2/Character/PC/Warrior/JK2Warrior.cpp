// Copyright 2024 All Rights Reserved by J&K


#include "JK2Warrior.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"



AJK2Warrior::AJK2Warrior()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DefaultMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone'"));
	if ( nullptr != DefaultMesh.Object )
	{
		Super::GetMesh()->SetSkeletalMesh(DefaultMesh.Object);
	}
}

void AJK2Warrior::BeginPlay()
{
	Super::BeginPlay();
}

void AJK2Warrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ( bWeaponActive )
		CheckWeaponTrace();
}

void AJK2Warrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
//JJH Assignment
void AJK2Warrior::SkillQ(const FInputActionValue& value)
{
	Super::SkillQ(value);
	UE_LOG(LogTemp, Log, TEXT("This is %s"), *this->GetName());
}

void AJK2Warrior::CheckWeaponTrace()
{
	if ( !bWeaponActive )
		return;

	FVector Start = GetMesh()->GetSocketLocation(FName(TEXT("FX_Sword_Bottom")));
	FVector End = GetMesh()->GetSocketLocation(FName(TEXT("FX_Sword_Top")));


	TArray<FHitResult> HitResults;

	bool bSuccess = UKismetSystemLibrary::SphereTraceMulti(
		this,
		Start,
		End,
		12.f,
		ETraceTypeQuery::TraceTypeQuery3,
		false,
		TArray <AActor*>(),
		EDrawDebugTrace::ForDuration,
		OUT HitResults,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		1.f);

	if ( bSuccess )
	{
		// FDamageEvent DamageEvent;

		for ( FHitResult& HitResult : HitResults )
		{
			AActor* Actor = HitResult.GetActor();
			if ( Actor == nullptr )
				continue;

			if ( WeaponAttackTargets.Contains(Actor) == false )
			{
				WeaponAttackTargets.Add(Actor);

				// TODO HitDamage
				UE_LOG(LogTemp, Log, TEXT("HitDamage: %s"), *Actor->GetName());

			}
		}
	}
}

void AJK2Warrior::Attack()
{
	Super::Attack();
}

void AJK2Warrior::ComboActionBegin()
{
	Super::ComboActionBegin();
}

void AJK2Warrior::DoCombo()
{
	Super::DoCombo();

	switch ( CurrentCombo )
	{
	case 0:
		CurrentCombo = 1;
		PlayAnimMontage(ComboActionMontage1,1.4f);
		break;
	case 1:
		CurrentCombo = 2;
		PlayAnimMontage(ComboActionMontage2, 1.4f);
		break;
	case 2:
		CurrentCombo = 3;
		PlayAnimMontage(ComboActionMontage3, 1.4f);
		break;
	}
}

void AJK2Warrior::ComboActionEnd()
{
	Super::ComboActionEnd();
}


