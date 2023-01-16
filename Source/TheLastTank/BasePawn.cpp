// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "TimerManager.h"
#include "Projectile.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>( TEXT("Capsule Collider") );
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Base Mesh") );
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Turret Mesh") );
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasePawn::RotateTurret(FVector Target, float DeltaTime)
{
	FVector ToTarget = Target - TurretMesh->GetComponentLocation();
	FRotator TargetRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(),
			TargetRotation,
			DeltaTime,
			InterpSpeed)
		);

}

void ABasePawn::Fire()
{
	if(CanShoot)
	{
		CanShoot = false;
		AProjectile* newProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation() );
		newProjectile->SetOwner(this);
		
		DrawDebugSphere(
			GetWorld(), 
			ProjectileSpawnPoint->GetComponentLocation(), 
			20.f, 
			12, 
			FColor::Blue, 
			false, 
			5.f);
		
	}
	
	
		
}

void ABasePawn::Reload()
{
	CanShoot = true;
}


void ABasePawn::HandleDestruction()
{
	//TODO: Visual/sound effects

	
}

