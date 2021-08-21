// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Player/RPGPlayerController.h"

ARPGPlayerController::ARPGPlayerController()
{

}

void ARPGPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void ARPGPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ARPGPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
