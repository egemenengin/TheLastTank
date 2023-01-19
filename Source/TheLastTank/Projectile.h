// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class THELASTTANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* MovementComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 LifeTime = 5;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Damage = 50;

	FTimerHandle ProjectileTimeHandler;

	UPROPERTY(EditAnyWhere, Category = "Effects")
	class UParticleSystem* HitParticles;
	
	UPROPERTY(VisibleAnyWhere, Category = "Effects")
	class UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnyWhere, Category = "Effects")
	class USoundBase* LaunchSound;

	UPROPERTY(EditAnyWhere, Category = "Effects")
	USoundBase* HitSound;

	UPROPERTY(EditAnyWhere, Category = "Effects")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;


	UFUNCTION()
	void OnHitHandle(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult);
};
