// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
    PrimaryActorTick.bCanEverTick = true;
    
    TankSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Tank Spring Arm"));
    TankSpringArm->SetupAttachment(RootComponent);

    TankCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Tank Camera"));
    TankCam->SetupAttachment(TankSpringArm);
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
    PlayerController = Cast<APlayerController>(GetController());

	if(PlayerController)
    {
        if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(InputMapping, 0);
        }
    }
    GetWorldTimerManager().SetTimer(FireTimeHandler, this, &ATank::Reload, ReloadSpeed, true); //TODO this should be in beginplay
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(PlayerController)
    {
        FHitResult HitResult; 
        bool IsHit = PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
        if(IsHit)
        {
            //DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 20, 10, FColor::Red, false, -1.f);
            RotateTurret(HitResult.ImpactPoint, DeltaTime);
        }

    }
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    UEnhancedInputComponent* PlayerEnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
    
    PlayerEnhancedInputComponent->BindAction(InputMove, ETriggerEvent::Triggered, this, &ATank::Move);
    PlayerEnhancedInputComponent->BindAction(InputTurn, ETriggerEvent::Triggered, this, &ATank::Turn);

    PlayerEnhancedInputComponent->BindAction(InputFire, ETriggerEvent::Started, this, &ATank::FireHandle);
}

void ATank::Move(const FInputActionValue& Value)
{
    FVector DeltaLocation = FVector(Value.Get<float>() ,0 ,0) * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
    AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(const FInputActionValue& Value)
{
    FRotator deltaRotation = FRotator(0, Value.Get<float>(), 0) * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnSpeed;
    AddActorLocalRotation(deltaRotation, true);
}

void ATank::FireHandle(const FInputActionValue& Value)
{
    if(Value.Get<bool>())
    {
        Fire();
    }
}

void ATank::HandleDestruction()
{
    Super::HandleDestruction();

    SetActorHiddenInGame(true);
    SetActorTickEnabled(false);

    bAlive = false;
}

