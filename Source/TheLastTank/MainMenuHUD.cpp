// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "Runtime/UMG/Public/UMG.h"

 bool UMainMenuHUD::Initialize()
 {
    bool bSuccess = Super::Initialize();
    if(!bSuccess)
    {
        return false;
    }

    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }

    if(!ensure(StartButton != nullptr)) return false;
    if(!ensure(SettingsButton != nullptr)) return false;
    if(!ensure(QuitButton != nullptr)) return false;
    if(!ensure(OpenInfoButton != nullptr)) return false;
    if(!ensure(InfoPanel != nullptr)) return false;
    if(!ensure(CloseInfoButton != nullptr)) return false;

    StartButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnStartButtonPressed);
    SettingsButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnSettingsButtonPressed);
    QuitButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnQuitButtonPressed);
    OpenInfoButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnOpenInfoButtonPressed);
    CloseInfoButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnCloseInfoButtonPressed);
    

    return true;
 } 


void UMainMenuHUD::OnStartButtonPressed()
{
    UGameplayStatics::OpenLevel(GetWorld(), "DemoMap");
}

void UMainMenuHUD::OnSettingsButtonPressed()
{
    //UGameplayStatics::OpenLevel(GetWorld(), "SettingsMap");
}

void UMainMenuHUD::OnQuitButtonPressed()
{
    if(PlayerControllerRef)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
    }
}


void UMainMenuHUD::OnOpenInfoButtonPressed()
{
    InfoPanel->SetVisibility(ESlateVisibility::Visible);
    InfoPanel->SetIsEnabled(true);

    OpenInfoButton->SetIsEnabled(false);
}

void UMainMenuHUD::OnCloseInfoButtonPressed()
{
    InfoPanel->SetVisibility(ESlateVisibility::Hidden);
    InfoPanel->SetIsEnabled(false);

    OpenInfoButton->SetIsEnabled(true);
}
