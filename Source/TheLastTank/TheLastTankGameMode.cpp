// Fill out your copyright notice in the Description page of Project Settings.


#include "TheLastTankGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "TheLastTankPlayerController.h"
void ATheLastTankGameMode::BeginPlay()
{
    Super::BeginPlay();

    HandleGameStart();
}
void ATheLastTankGameMode::ActorDied(AActor* DeadActor)
{
    if(DeadActor != nullptr)
    {
        if(DeadActor->ActorHasTag(TankTag))
        {
            Tank->HandleDestruction();
            if(Tank->GetTankPlayerController())
            {
                TheLastTankPlayerController->SetPlayerEnabledState(false);
            } 
        }
        else if(DeadActor->ActorHasTag(TowerTag))
        {
            ATower* Tower = Cast<ATower>(DeadActor);
            Tower->HandleDestruction();
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("UNKNOWN DEAD ACTOR"));
        }
        
    }
    
    
}

void ATheLastTankGameMode::HandleGameStart()
{
    Tank  = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
    TheLastTankPlayerController = Cast<ATheLastTankPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    StartGame();
    
    if(TheLastTankPlayerController)
    {
        TheLastTankPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerEnableTimerHandle;
        FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(TheLastTankPlayerController, &ATheLastTankPlayerController::SetPlayerEnabledState, true);
        GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableDelegate, StartDelay, false);

    }
}

