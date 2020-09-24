// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayerInfoFunctionLibrary.generated.h"

/**
 * 
 */

class APawn;

UENUM(BlueprintType)
enum class ETeam : uint8
{
	Team1 = 0,
	Team2 = 1,
	Monster = 2
};

UENUM(BlueprintType)
enum class EPlayerRole : uint8
{
	Defence,
	Offence,
};

USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerInfo")
	FText PlayerName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerInfo")
	EPlayerRole PlayerRole;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerInfo")
	TSubclassOf<APawn> PawnType;

	// UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerInfo")
	// TArray<int> SucceededLevelList;
};

UCLASS()
class NETTD_API UPlayerInfoFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "MissionInfo")
	static bool IsValid(const FPlayerInfo& Info)
	{
		return !Info.PlayerName.IsEmpty();
	}
};
