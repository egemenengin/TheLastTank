// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{

}

void ATower::BeginPlay()
{
    Super::BeginPlay();
    PlayerTank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    GetWorldTimerManager().SetTimer(FireTimeHandler, this, &ATower::Reload, ReloadSpeed, true); 
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(PlayerTank && IsInRange())
    {
        RotateTurret(PlayerTank->GetActorLocation(), DeltaTime);
        Fire();
    }

}


bool ATower::IsInRange()
{
    if(PlayerTank == nullptr)
    {
        return false;
    }

    float DistToTank = FVector::Dist(GetActorLocation(), PlayerTank->GetActorLocation());

    if( (DistToTank <= FireRange) && (PlayerTank->bAlive == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}


void ATower::HandleDestruction()
{
    Super::HandleDestruction();

    Destroy();
}
