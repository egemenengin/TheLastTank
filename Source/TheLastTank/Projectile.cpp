// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Kismet/GameplayStatics.h"
// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh") );
	
	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement Comp") );
	MovementComp->MaxSpeed = 1500.f;
	MovementComp->InitialSpeed = 1500.f; 
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	//TODO ADD LIFETIME GetWorldTimerManager().SetTimer(ProjectileTimeHandler, this, &AActor::Destroy(), LifeTime, false);
	
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHitHandle);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AProjectile::OnHitHandle(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult){
	//UE_LOG(LogTemp, Display, TEXT("HIT %s TO %s COMP: %s"), *(HitComp->GetName()), *(OtherActor->GetName()), *(OtherComp->GetName()));

	if(GetOwner() == nullptr) return;

	if(OtherActor && OtherActor != this && OtherActor != GetOwner())
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, GetOwner()->GetInstigatorController(), this, UDamageType::StaticClass());
		Destroy();
	}
	
}
