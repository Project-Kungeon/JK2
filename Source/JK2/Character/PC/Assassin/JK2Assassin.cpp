// Copyright 2024 All Rights Reserved by J&K

#include "JK2Assassin.h"
#include "Kismet/KismetSystemLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(JK2Assassin)



AJK2Assassin::AJK2Assassin()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DefaultMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonKallari/Characters/Heroes/Kallari/Skins/Rogue/Meshes/Kallari_Rogue.Kallari_Rogue'"));
	if (DefaultMesh.Succeeded())
		Super::GetMesh()->SetSkeletalMesh(DefaultMesh.Object);
}

void AJK2Assassin::BeginPlay()
{
	Super::BeginPlay();
}

void AJK2Assassin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ( bWeaponActive )
		CheckWeaponTrace();
}

void AJK2Assassin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AJK2Assassin::CheckWeaponTrace()
{
	if ( !bWeaponActive )
		return;

	FVector StartL = GetMesh()->GetSocketLocation(FName(TEXT("sword_base_l")));
	FVector StartR = GetMesh()->GetSocketLocation(FName(TEXT("sword_base_l")));
	FVector EndL = GetMesh()->GetSocketLocation(FName(TEXT("sword_tip_r")));
	FVector EndR = GetMesh()->GetSocketLocation(FName(TEXT("sword_tip_r")));

	TArray<FHitResult> HitResults;

	bool bSuccessL = UKismetSystemLibrary::SphereTraceMulti(
		this,
		StartL,
		EndL,
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
	
	bool bSuccessR = UKismetSystemLibrary::SphereTraceMulti(
		this,
		StartR,
		EndR,
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

	if ( bSuccessL|| bSuccessR )
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
				UE_LOG(LogTemp, Log, TEXT("HitDamage"));
				
			}
		}
	}
}
