// Copyright 2024 All Rights Reserved by J&K


#include "JK2Archor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"

AJK2Archor::AJK2Archor()
{
	//Path of Arrow Actor Blueprint Class
	//해당 부분 C++ Class 로 전환
	path = TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Actor/BP_Arrow.BP_Arrow'");

	//Montage 상하체 미 분리때문에 발생하는 현상
	//GetCharacterMovement()->bOrientRotationToMovement = false;
	//bUseControllerRotationYaw = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DefaultMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSparrow/Characters/Heroes/Sparrow/Meshes/Sparrow.Sparrow'"));
	if ( nullptr != DefaultMesh.Object )
	{
		Super::GetMesh()->SetSkeletalMesh(DefaultMesh.Object);
	} 

	//이렇게 해야 애니메이션이 두번 동작 안함
	GetCharacterMovement()->JumpZVelocity = 400.f;
	GetCharacterMovement()->AirControl = 1.f;
}

void AJK2Archor::BeginPlay()
{
	Super::BeginPlay();
}

void AJK2Archor::Attack()
{
	Super::Attack();
}

void AJK2Archor::Shoot()
{
	/*
	사격게임에서 하는 히트 스캔 방식을 사용했습니다.
	
	스캔을 하고 오브젝트가 탐지되면 거리를 계산해서 발사하는 방식으로

	1. UI(조준선)가 잇는 월드 위치->카메라의 중심
	*/
	FVector ArrowSpawnLocation;
	FRotator ArrowSpawnRotation;
	UBlueprint* ObjectToSpawn = Cast<UBlueprint>(StaticLoadObject(UBlueprint::StaticClass(), nullptr, *path.ToString()));
	FActorSpawnParameters SpawnParams;
	FRotator rotator = GetControlRotation();
	//Skeletal mesh의 idle 상태에서 화살 촉이 있는 부분
	FVector ShootPoint = GetMesh()->GetSocketLocation(FName(TEXT("BowEmitterSocket")));
	FHitResult HitResult;
	//Location Of Camera(Line Trace start)
	FVector CrosshairWorldLocation;
	FVector EndLocation;
	FVector ImpactPoint;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TEnumAsByte<EObjectTypeQuery> WorldStatic = UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic);
	TEnumAsByte<EObjectTypeQuery> WorldDynamic = UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic);
	ObjectTypes.Add(WorldStatic);
	ObjectTypes.Add(WorldDynamic);


	//Camera Info 가져오기.
	if ( GetWorld() )
	{
		APlayerCameraManager* CameraManager = Cast<APlayerCameraManager>(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0));
		if ( CameraManager )
		{
			CrosshairWorldLocation = CameraManager->GetCameraLocation();
			//카메라의 전방 벡터 가져오기.
			EndLocation = CameraManager->GetActorForwardVector();
			//scaling forward vector by 15,000, 추적의 끝 부분, Multifly Vector Size 15000
			EndLocation.X *= 15000;
			EndLocation.Y *= 15000;
			EndLocation.Z *= 15000;
			//탐지하고자 하는 끝부분, Impact Target Point
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
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		1.f);
	if ( IsSuccess )
	{
		if ( HitResult.bBlockingHit )
		{
			ImpactPoint = HitResult.ImpactPoint;
			UE_LOG(LogTemp, Log, TEXT("%d, %d, %d"), ImpactPoint.X, ImpactPoint.Y, ImpactPoint.Z);
		}
		ArrowSpawnLocation = ShootPoint;
		ArrowSpawnRotation = (ImpactPoint - ArrowSpawnLocation).Rotation();
	}
	//rotator = GetControlRotation();
	//ShootPoint = GetMesh()->GetSocketLocation(FName(TEXT("arrow_anchor")));
	//화살 생성
	UE_LOG(LogTemp, Log, TEXT("%d %d %d"), )
	GetWorld()->SpawnActor<AActor>(ObjectToSpawn->GeneratedClass, ArrowSpawnLocation, ArrowSpawnRotation, SpawnParams);
}

void AJK2Archor::ComboActionBegin()
{
	Super::ComboActionBegin();
}

void AJK2Archor::DoCombo()
{
	Super::DoCombo();
	switch ( CurrentCombo ) 
	{
		case 0:
			CurrentCombo = 1;
			PlayAnimMontage(ComboActionMontage, 1.f);
			Shoot();
			break;
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
