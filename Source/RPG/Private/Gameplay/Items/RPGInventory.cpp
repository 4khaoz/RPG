// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Items/RPGInventory.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
URPGInventory::URPGInventory()
{
	InventorySlotsLimit = 60;
	InventoryWeightLimit = 500.f;
}


void URPGInventory::ServerAddItem_Implementation(URPGItem* item)
{
	// Iterate through all Inventory Slots
	int emptySlot = -1;
	for (int i = 0; i < InventorySlotsLimit; i++)
	{
		
	}
	ClientOnInventoryUpdate();
}

void URPGInventory::ServerRemoveItem_Implementation()
{
}

void URPGInventory::ServerInsertItemAtIndex_Implementation(URPGItem* item, int index)
{
	if (InventoryContainer.IsValidIndex(index))
	{

	}
}

URPGItem* URPGInventory::GetItemAt(int index)
{
	if (InventoryContainer.IsValidIndex(index))
	{
		return InventoryContainer[index].Item;
	}
	return NULL;
}

int URPGInventory::GetNumberOfUsedSlots()
{
	int UsedSlotsCount = 0;
	for (auto& slot : InventoryContainer)
	{
		if (slot.Item != NULL)
		{
			UsedSlotsCount++;
		}
	}
	return UsedSlotsCount;
}

float URPGInventory::GetInventoryWeight()
{
	float TotalWeight = 0;
	for (auto& slot : InventoryContainer)
	{
		TotalWeight += slot.Item->GetItemWeight() * slot.ItemStacks;
	}
	return TotalWeight;
}

void URPGInventory::ClientOnInventoryUpdate_Implementation()
{
	// Call OnRep-Functio on Client to trigger InventoryUpdate in Widget
	OnRep_Inventory();
}

void URPGInventory::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(URPGInventory, InventoryContainer);
}

bool URPGInventory::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	Super::ReplicateSubobjects(Channel, Bunch, RepFlags);

	return false;
}

// Called when the game starts
void URPGInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void URPGInventory::OnRep_Inventory()
{
	OnInventoryUpdate.Broadcast();
}
