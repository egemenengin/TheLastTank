// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGameMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class THELASTTANK_API UEndGameMenuHUD : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;
public:
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* MainMenuButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* PlayAgainButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitButton;


	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess))
	class APlayerController* PlayerControllerRef;

	UFUNCTION()
	void OnMainMenuButtonPressed();

	UFUNCTION()
	void OnPlayAgainButtonPressed();	

	UFUNCTION()
	void OnQuitButtonPressed();	
};
