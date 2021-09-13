// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Player/RPGPlayerState.h"
#include "Gameplay/Items/RPGInventory.h"

ARPGPlayerState::ARPGPlayerState()
{
	Inventory = CreateDefaultSubobject<URPGInventory>(TEXT("Inventory"));
}

URPGInventory* ARPGPlayerState::GetInventory()
{
	return Inventory;
}
