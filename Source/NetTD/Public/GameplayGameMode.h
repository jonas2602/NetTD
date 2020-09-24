// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayGameMode.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class NETTD_API AGameplayGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Default")
	void RespawnPlayer(APlayerController* Controller, TSubclassOf<APawn> PawnClass);
};
