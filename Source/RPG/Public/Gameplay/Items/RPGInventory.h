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
		: SlotIndex(-1)
	{ }

	FItemSlot(int slot, URPGItem* item)
		: SlotIndex(slot)
		, SlottedItem(item)
	{ }

	UPROPERTY(BlueprintReadOnly)
	int SlotIndex;

	UPROPERTY(BlueprintReadOnly)
	URPGItem* SlottedItem;

	bool operator<(const FItemSlot& other) const
	{
		return SlotIndex < other.SlotIndex;
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

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ServerAddItem(URPGItem* item);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ServerRemoveItem();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ServerInsertItem(URPGItem* item, int slot);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	URPGItem* GetItemAt(int index);

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

	int InventoryCapacity;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Inventory)
	TArray<FItemSlot> InventoryContainer;

	UFUNCTION()
	void OnRep_Inventory();
};