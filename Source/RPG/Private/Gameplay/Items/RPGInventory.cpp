// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Items/RPGInventory.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
URPGInventory::URPGInventory()
{
	Capacity = 80;
}

bool URPGInventory::ServerAddItem_Validate(URPGItem* item)
{
	// HTTP Call to add item to Database
	// Successful if Response Success
	

	return true;
}

void URPGInventory::ServerAddItem_Implementation(URPGItem* item)
{
	InventoryContainer.Add(FItemSlot(item));
	ClientOnInventoryUpdate();
}

bool URPGInventory::ServerRemoveItem_Validate(int index)
{
	if (!InventoryContainer.IsValidIndex(index)) 
		return false;
	return true;
}

void URPGInventory::ServerRemoveItem_Implementation(int index)
{
	InventoryContainer.RemoveAt(index);
}

URPGItem* URPGInventory::GetItemAt(int index)
{
	if (InventoryContainer.IsValidIndex(index))
	{
		return InventoryContainer[index].Item;
	}
	return nullptr;
}

int URPGInventory::GetNumberOfUsedSlots()
{
	int UsedSlotsCount = 0;
	for (auto& slot : InventoryContainer)
	{
		if (slot.Item)
		{
			UsedSlotsCount++;
		}
	}
	return UsedSlotsCount;
}

int URPGInventory::GetInventoryCapacity()
{
	return Capacity;
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
