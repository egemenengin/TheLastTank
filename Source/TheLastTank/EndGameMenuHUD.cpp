// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameMenuHUD.h"
#include "Runtime/UMG/Public/UMG.h"

bool UEndGameMenuHUD::Initialize()
{
    bool bSuccess = Super::Initialize();

    if(!bSuccess) return false;

    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }
    
    if(!ensure(MainMenuButton != nullptr)) return false;
    if(!ensure(QuitButton != nullptr)) return false;
    
    MainMenuButton->OnClicked.AddDynamic(this, &UEndGameMenuHUD::OnMainMenuButtonPressed);
    QuitButton->OnClicked.AddDynamic(this, &UEndGameMenuHUD::OnQuitButtonPressed);

    return bSuccess; 
}

void UEndGameMenuHUD::OnMainMenuButtonPressed()
{
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenuMap");
}

void UEndGameMenuHUD::OnQuitButtonPressed()
{
    if(PlayerControllerRef)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
    }
}
void UEndGameMenuHUD::OnPlayAgainButtonPressed()
{
    UGameplayStatics::OpenLevel(GetWorld(), "DemoMap");
}