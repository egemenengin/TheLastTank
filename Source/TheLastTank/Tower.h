// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class THELASTTANK_API ATower : public ABasePawn
{
	GENERATED_BODY()
public:
	ATower();
	// Called Every Frame
	virtual void Tick(float DeltaTime) override;

	bool IsInRange();
	
	void HandleDestruction();
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Shoot", meta = (AllowPrivateAccess = "true"))
	float FireRange;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Shoot", meta = (AllowPrivateAccess = "true"))
	class ATank* PlayerTank;

		

};
