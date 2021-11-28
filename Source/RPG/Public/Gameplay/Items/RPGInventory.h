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

	// Default Constructor
	FItemSlot()
		: ItemStacks(0)
	{ }

	FItemSlot(URPGItem* item)
		: Item(item)
		, ItemStacks(1)
	{ }

	UPROPERTY(BlueprintReadOnly)
	URPGItem* Item;

	UPROPERTY(BlueprintReadOnly)
	int ItemStacks;

	bool operator==(const FItemSlot& other) const
	{
		return Item == other.Item;
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

	/* Add Item to Inventory */
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ServerAddItem(URPGItem* item);

	/* Remove Item from Inventory */
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ServerRemoveItem();

	/* Insert Item at specified Inventory index */
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ServerInsertItemAtIndex(URPGItem* item, int index);
	
	/* Get Item at specified Inventory index */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	URPGItem* GetItemAt(int index);

	/* Get Number of Inventory Slots used */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetNumberOfUsedSlots();

	/* Get Total Weight of all Items in Inventory */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetInventoryWeight();
	
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

	int InventorySlotsLimit;
	float InventoryWeightLimit;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Inventory)
	TArray<FItemSlot> InventoryContainer;

	UFUNCTION()
	void OnRep_Inventory();
};
