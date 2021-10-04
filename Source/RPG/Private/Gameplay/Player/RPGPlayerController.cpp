// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Player/RPGPlayerController.h"
#include "Gameplay/Items/RPGInventory.h"
#include "Net/UnrealNetwork.h"

ARPGPlayerController::ARPGPlayerController()
{
	Inventory = CreateDefaultSubobject<URPGInventory>(TEXT("Inventory"));
	if (Inventory)
	{
		Inventory->SetIsReplicated(true);
	}
}

void ARPGPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARPGPlayerController, Inventory);
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

void ARPGPlayerController::EnableCursorMode()
{
	SetInputMode(FInputModeGameAndUI());
	SetCursorToCenter();
	SetShowMouseCursor(true);
}

void ARPGPlayerController::DisableCursorMode()
{
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
}

void ARPGPlayerController::SetCursorToCenter()
{
	FVector2D dimension;
	GetLocalPlayer()->ViewportClient->GetViewportSize(dimension);

	const int x = dimension.X * 0.5f;
	const int y = dimension.Y * 0.5f;
	SetMouseLocation(x, y);
}
