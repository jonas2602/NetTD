// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAIController.h"



ETeamAttitude::Type ABaseAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	ETeamAttitude::Type Attitude;
	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(&Other);
	if (OtherTeamAgent)
	{
		Attitude = FGenericTeamId::GetAttitude(GetGenericTeamId(), OtherTeamAgent->GetGenericTeamId());
	}
	else
	{
		UE_LOG(LogClass, Error, TEXT("%s is no TeamAgent"), *Other.GetName());
		Attitude = ETeamAttitude::Neutral;
	}

	return Attitude;
}

void ABaseAIController::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	IGenericTeamAgentInterface* ControlledAgent = Cast<IGenericTeamAgentInterface>(GetPawn());
	if (ControlledAgent)
	{
		ControlledAgent->SetGenericTeamId(NewTeamID);
	}
}


FGenericTeamId ABaseAIController::GetGenericTeamId() const
{
	const IGenericTeamAgentInterface* ControlledAgent = Cast<const IGenericTeamAgentInterface>(GetPawn());
	if (ControlledAgent)
	{
		return ControlledAgent->GetGenericTeamId();
	}

	return FGenericTeamId();
}