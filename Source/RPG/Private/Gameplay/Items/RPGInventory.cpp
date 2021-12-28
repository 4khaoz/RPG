// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Items/RPGInventory.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
URPGInventory::URPGInventory()
{
	InventorySlotsLimit = 60;
	InventoryWeightLimit = 500.f;
}

bool URPGInventory::ServerAddItem_Validate(URPGItem* item)
{
	// Check if InventoryWeightLimit is reached
	if (GetInventoryWeight() + item->GetItemWeight() > InventoryWeightLimit)
	{
		// LOGMSG InventoryWeightLimit reached - Cannot Add Item
		return false;
	}

	if (FindFirstFreeSlot() == -1)
	{
		return false;
	}

	// HTTP Call to add item to Database
	// Successful if Response Success
	

	return true;
}

void URPGInventory::ServerAddItem_Implementation(URPGItem* item)
{
	InventoryContainer[FindFirstFreeSlot()] = FItemSlot(item);
	ClientOnInventoryUpdate();
}

bool URPGInventory::ServerRemoveItemByIndex_Validate()
{
	return true;
}

void URPGInventory::ServerRemoveItemByIndex_Implementation()
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

int URPGInventory::GetInventorySlotsLimit()
{
	return InventorySlotsLimit;
}

float URPGInventory::GetInventoryWeightLimit()
{
	return InventoryWeightLimit;
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

int URPGInventory::FindFirstFreeSlot()
{
	// -1 means it is invalid
	int index = -1;
	for (int i = 0; i < InventorySlotsLimit; i++)
	{
		if (!InventoryContainer[index].Item)
		{
			index = i;
			break;
		}
	}
	return index;
}

void URPGInventory::OnRep_Inventory()
{
	OnInventoryUpdate.Broadcast();
}
