// Copyright 2024 All Rights Reserved by J&K

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

UCLASS()
class JK2_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Root)
	TObjectPtr<class USceneComponent> DefaultRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = StaticMesh)
	TObjectPtr<class UStaticMeshComponent> Arrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision)
	TObjectPtr<class UBoxComponent> Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile)
	TObjectPtr<class UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Effect)
	TObjectPtr<class UParticleSystem> Particle;

	UFUNCTION()
	void OnComponentOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
};
