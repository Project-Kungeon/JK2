// Copyright 2024 All Rights Reserved by J&K


#include "JK2Warrior.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "JK2/Physics/JK2Collision.h"
#include "TimerManager.h"
#include "Particles/ParticleSystemComponent.h"


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

void AJK2Warrior::SkillQ(const FInputActionValue& value)
{
	Super::SkillQ(value);
	UE_LOG(LogTemp, Log, TEXT("This is %s"), *this->GetName());
}

void AJK2Warrior::SkillE(const FInputActionValue& value)
{
	Super::SkillE(value);
}

void AJK2Warrior::SkillR(const FInputActionValue& value)
{
	Super::SkillR(value);
	PlayAnimMontage(SkillRMontage, 1.4f);
	PlayParticleSystem();
	CheckSkillRTrace();

}

void AJK2Warrior::SkillLShift(const FInputActionValue& value)
{
	Super::SkillLShift(value);
}

void AJK2Warrior::CheckWeaponTrace()
{
	if ( !bWeaponActive )
		return;

	FVector Start = GetMesh()->GetSocketLocation(FName(TEXT("FX_Sword_Bottom")));
	FVector End = GetMesh()->GetSocketLocation(FName(TEXT("FX_Sword_Top")));
	FVector Extend = End - Start;
	const float AttackRadius = 20.f;

	TArray<FHitResult> HitResults;
	//FHitResult HitResult;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), false, this);
	
	/*  sweep / multi / ByChannel */

	bool bSuccess = GetWorld()->SweepMultiByChannel(
		HitResults,
		Start,
		End,
		FQuat::Identity,
		CCHANNEL_JK2ACTION,
		FCollisionShape::MakeCapsule(Extend),
		Params
	);

	if ( bSuccess )
	{
		//FDamageEvent DamageEvent;

		for ( FHitResult& HitResult : HitResults )
		{
			AActor* Actor = HitResult.GetActor();
			if ( Actor == nullptr )
				continue;

			if ( WeaponAttackTargets.Contains(Actor) == false )
			{
				WeaponAttackTargets.Add(Actor);

				// TODO HitDamage
				// Server Code need
				UE_LOG(LogTemp, Log, TEXT("HitDamage: %s"), *Actor->GetName());


			}
		}
		
	}

#if ENABLE_DRAW_DEBUG
	FVector Direction = End - Start;
	float CapsuleHalfHeight = Direction.Size() / 2.f;
	FVector CapsuleOrigin = Start + (End - Start) / 2.f;
	FColor DrawColor = bSuccess ? FColor::Green : FColor::Red;
	FQuat QuatRotation = FQuat::FindBetweenNormals(FVector::UpVector, Direction.GetSafeNormal());

	DrawDebugCapsule(
		GetWorld(),
		CapsuleOrigin,
		CapsuleHalfHeight,
		AttackRadius,
		QuatRotation,
		DrawColor,
		false,
		1.f,
		0
	);
	
#endif
}

void AJK2Warrior::PlayParticleSystem()
{
	FTimerHandle TimerHandle;
	//timer
	const float Duration = 5.f;

	ParticleSystemComponent = UGameplayStatics::SpawnEmitterAttached(
		SkillREffect,
		GetMesh(),
		TEXT("NONE"),
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		EAttachLocation::KeepRelativeOffset,
		false
	);

	if ( ParticleSystemComponent )
	{
		// 파티클 시스템 재생
		ParticleSystemComponent->Activate(true);

		// 일정 시간 후에 파티클 시스템 제거를 위한 타이머 설정
		GetWorldTimerManager().SetTimer(
			TimerHandle,
			this,
			&AJK2Warrior::StopParticleSystem,
			Duration,
			false
		);
	}
}

void AJK2Warrior::CheckSkillRTrace()
{
	TArray<FOverlapResult> HitResults;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), false, this);

	bool bSuccess = GetWorld()->OverlapMultiByChannel(
		HitResults,
		GetActorLocation(),
		FQuat::Identity,
		CCHANNEL_JK2ACTION,
		FCollisionShape::MakeSphere(400.0f),
		Params
	);

	if ( bSuccess )
	{
		for ( const FOverlapResult& HitResult : HitResults )
		{
			AActor* OverlappingActor = HitResult.GetActor();
			//Take Damage
			
			FVector OverlapLocation = OverlappingActor->GetActorLocation();
			float SphereRadius = 50.0f; 
			FColor SphereColor = FColor::Green;
			float LifeTime = 5.0f;
			
			DrawDebugSphere(
				GetWorld(),
				OverlapLocation,
				SphereRadius,
				32,
				SphereColor,
				false,
				LifeTime
			);
		}
	}
	
}

void AJK2Warrior::StopParticleSystem()
{
	if ( ParticleSystemComponent )
	{
		ParticleSystemComponent->Deactivate();
		ParticleSystemComponent->DestroyComponent();
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


