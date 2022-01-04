// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RPGItem.h"
#include "RPGInventory.generated.h"

USTRUCT(BlueprintType)
struct FItemSlot
{
	GENERATED_USTRUCT_BODY()

	// Default Constructor, -1 means invalid
	FItemSlot() 
		: SlotIndex(-1)
	{ }

	FItemSlot(URPGItem* item, uint8 index)
		: Item(item)
		, SlotIndex(index)
	{ }

	UPROPERTY(BlueprintReadOnly)
	URPGItem* Item;

	UPROPERTY(BlueprintReadOnly)
	uint8 SlotIndex;

	UPROPERTY(BlueprintReadOnly)
	int Stacks;

	bool IsEmpty()
	{
		return Item == nullptr;
	}

	bool operator==(const FItemSlot& other) const
	{
		return Item == other.Item && SlotIndex == other.SlotIndex;
	}
};

// BP will bind this to update User Interface
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryUpdate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_API URPGInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URPGInventory();

	///////////////////////////////////////////////////////////////////////////
	// Server Functions

	/* Add Item to Inventory */
	UFUNCTION(BlueprintCallable, Server, WithValidation, Reliable)
	void ServerAddItem(URPGItem* item);

	/* Remove Item from Inventory */
	UFUNCTION(BlueprintCallable, Server, WithValidation, Reliable)
	void ServerRemoveItemByIndex();

	/* Insert Item at specified Inventory index */
	UFUNCTION(BlueprintCallable, Server, WithValidation, Reliable)
	void ServerInsertItemAtIndex(URPGItem* item, int index);
	
	///////////////////////////////////////////////////////////////////////////
	// Getters

	/* Get Item at specified Inventory index */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	URPGItem* GetItemAt(int index);

	/* Get Number of Inventory Slots used */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetNumberOfUsedSlots();

	/* Get Slots Limit of Inventory */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetInventoryCapacity();
	
	/**
	Delegates & ClientSide Call
	*/
	UPROPERTY(BlueprintAssignable)
	FInventoryUpdate OnInventoryUpdate;

	UFUNCTION(Client, Reliable)
	void ClientOnInventoryUpdate();


	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;
	
	/** Method that allows an Actor to replicate subobjects on its Actor channel */
	virtual bool ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags);



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Returns index of first free slot, -1 if invalid
	int FindFirstFreeSlot();
	int FreeSlotIndex;

	// Maximum number of items in the inventory
	int Capacity;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Inventory)
	TArray<FItemSlot> InventoryContainer;

	UFUNCTION()
	void OnRep_Inventory();
};
