// Fill out your copyright notice in the Description page of Project Settings.


#include "TheLastTankPlayerController.h"


void ATheLastTankPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    bShowMouseCursor = bPlayerEnabled;
    if(bPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
    }
    else
    {
        GetPawn()->DisableInput(this);
    }
}