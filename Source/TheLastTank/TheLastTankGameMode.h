// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheLastTankGameMode.generated.h"

/**
 * 
 */
UCLASS()
class THELASTTANK_API ATheLastTankGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

public:

	void ActorDied(AActor* DeadActor);
	

private:

	void HandleGameStart();

	int32 GetNumberOfTower();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Player" , meta = (AllowPrivateAccess = "true"))
	class ATank* Tank;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Player" , meta = (AllowPrivateAccess = "true"))
	class ATheLastTankPlayerController* TheLastTankPlayerController;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Tags" , meta = (AllowPrivateAccess = "true"))
	FName TankTag;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Tags" , meta = (AllowPrivateAccess = "true"))
	FName TowerTag;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Start Game" , meta = (AllowPrivateAccess = "true"))
	float StartDelay = 5.f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Start Game" , meta = (AllowPrivateAccess = "true"))
	int32 RemainingTower = 0; 



};
