// Copyright 2024 All Rights Reserved by J&K


#include "JK2Archor.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"

AJK2Archor::AJK2Archor()
{
	path = TEXT("Blueprint'/Game/Blueprints/Actor/BP_Arrow.BP_Arrow'");

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
	FVector ArrowSpawnLocation;
	FRotator ArrowSpawnRotation;
	UBlueprint* ObjectToSpawn = Cast<UBlueprint>(StaticLoadObject(UBlueprint::StaticClass(), nullptr, *path.ToString()));
	FActorSpawnParameters SpawnParams;
	FRotator rotator = GetControlRotation();
	FVector ShootPoint = GetMesh()->GetSocketLocation(FName(TEXT("arrow_anchor")));
	FHitResult HitResult;
	FVector CrosshairWorldLocation;
	FVector EndLocation;
	FVector ImpactPoint;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TEnumAsByte<EObjectTypeQuery> WorldStatic = UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic);
	TEnumAsByte<EObjectTypeQuery> WorldDynamic = UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic);
	ObjectTypes.Add(WorldStatic);
	ObjectTypes.Add(WorldDynamic);


	if ( GetWorld() )
	{
		APlayerCameraManager* CameraManager = Cast<APlayerCameraManager>(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0));
		if ( CameraManager )
		{
			CrosshairWorldLocation = CameraManager->GetCameraLocation();
			EndLocation = CameraManager->GetActorForwardVector();
			//scaling forward vector by 15,000
			EndLocation.X *= 15000;
			EndLocation.Y *= 15000;
			EndLocation.Z *= 15000;
			ImpactPoint = CrosshairWorldLocation + EndLocation;
		}
	}
	bool IsSuccess = UKismetSystemLibrary::LineTraceSingleForObjects(
		this,
		CrosshairWorldLocation,
		ImpactPoint,
		ObjectTypes,
		false,
		TArray <AActor*>(),
		EDrawDebugTrace::ForDuration,
		OUT HitResult,
		true);
	if ( IsSuccess )
	{
		if ( HitResult.bBlockingHit )
		{
			ImpactPoint = HitResult.ImpactPoint;
			
		}
		else
		{
			ArrowSpawnLocation = ShootPoint;
		}
		ArrowSpawnRotation = (ImpactPoint - ArrowSpawnLocation).Rotation();
	}
	rotator = GetControlRotation();
	ShootPoint = GetMesh()->GetSocketLocation(FName(TEXT("arrow_anchor")));
	GetWorld()->SpawnActor<AActor>(ObjectToSpawn->GeneratedClass, ShootPoint, rotator, SpawnParams);
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
