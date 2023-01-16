// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheLastTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THELASTTANK_API ATheLastTankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);
		
};
