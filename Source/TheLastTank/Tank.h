// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputActionValue.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class THELASTTANK_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const{ return PlayerController; }
private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TankCam;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* TankSpringArm;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite,  Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Speed = 20.f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite,  Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float TurnSpeed = 20.f;

	
	UPROPERTY()
	class APlayerController* PlayerController;

public: 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	class UInputMappingContext* InputMapping;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
    class UInputAction* InputMove;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	class UInputAction* InputTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
    class UInputAction* InputFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
    class UInputAction* InputRotateTurret;

	// Handle forward and backward movement inputs
	void Move(const FInputActionValue& Value);	
	// Handle inputs of turning of the tank  
	void Turn(const FInputActionValue& Value);
	//Handle input of fire
	void FireHandle(const FInputActionValue& Value);
};
