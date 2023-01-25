// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class THELASTTANK_API UMainMenuHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;
public: 

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* StartButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* SettingsButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* OpenInfoButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UCanvasPanel* InfoPanel;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* CloseInfoButton;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* PlayerControllerRef;


	UFUNCTION()
	void OnStartButtonPressed();

	UFUNCTION()
	void OnSettingsButtonPressed();

	UFUNCTION()
	void OnQuitButtonPressed();

	UFUNCTION()
	void OnOpenInfoButtonPressed();

	UFUNCTION()
	void OnCloseInfoButtonPressed();	
};
