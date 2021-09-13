// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Items/RPGInventory.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
URPGInventory::URPGInventory()
{
	InventoryCapacity = 60;
}


void URPGInventory::ServerAddItem_Implementation(URPGItem* item)
{
	if (InventoryContainer.Num() < InventoryCapacity)
	{
		// Sort Inventory by SlotIndex
		InventoryContainer.Sort([](const FItemSlot& a, const FItemSlot& b) { return a < b; });

		int i = 0;
		for (FItemSlot& it : InventoryContainer)
		{
			if (it.SlotIndex != i)
			{
				break;
			}
			i++;
		}
		InventoryContainer.Add(FItemSlot(i, item));
		ClientOnInventoryUpdate();
	}
}

void URPGInventory::ServerRemoveItem_Implementation()
{
}

void URPGInventory::ServerInsertItem_Implementation(URPGItem* item, int slot)
{
}

URPGItem* URPGInventory::GetItemAt(int index)
{
	return nullptr;
}

int URPGInventory::GetInventoryCapacity()
{
	return InventoryCapacity;
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
