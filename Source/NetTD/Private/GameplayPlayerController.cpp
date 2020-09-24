// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayPlayerController.h"


void AGameplayPlayerController::OnUnPossess()
{
	PreviousPawn = GetPawn();
	Super::OnUnPossess();
}