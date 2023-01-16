//----------------------------------------------------------
// Project: TheLastTank
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: BasePawn.h
// UE Version: 5.1
// Date: 12/2022
//----------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class THELASTTANK_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void HandleDestruction();
protected:
	void RotateTurret(FVector Target, float DeltaTime);

	void Fire();
	void Reload();

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite,  Category = "Projectile", meta = (AllowPrivateAccess = "true"))
 	int32 ReloadSpeed = 2;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite,  Category = "Projectile", meta = (AllowPrivateAccess = "true"))
 	bool CanShoot = true;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite,  Category = "Projectile", meta = (AllowPrivateAccess = "true"))
 	FTimerHandle FireTimeHandler;

	

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
 	float InterpSpeed = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
 	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AProjectile> ProjectileClass;
};
