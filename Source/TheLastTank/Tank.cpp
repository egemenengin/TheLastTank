// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ATank::ATank()
{
    PrimaryActorTick.bCanEverTick = true;
    
    TankSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Tank Spring Arm"));
    TankSpringArm->SetupAttachment(RootComponent);

    TankCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Tank Camera"));
    TankCam->SetupAttachment(TankSpringArm);
}