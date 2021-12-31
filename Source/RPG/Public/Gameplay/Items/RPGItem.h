// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../Networking/RPGHttp_Items.h"
#include "RPGItem.generated.h"

UENUM(BlueprintType)
enum class EItemQuality : uint8
{
	Common		UMETA(DisplayName = "Common"),		// White Grey
	Uncommon	UMETA(DisplayName = "Uncommon"),	// Green
	Superior	UMETA(DisplayName = "Superior"),	// Blue
	Epic		UMETA(DisplayName = "Epic"),		// Purple
	Legendary	UMETA(DisplayName = "Legendary"),	// Yellow Gold / Orange
	Legacy		UMETA(DisplayName = "Legacy")		// Red
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	// Gear
	Weapon,
	Shield,
	Helmet,
	BodyArmor,
	Gloves,
	Pants,
	Ring,
	Amulet,
	Artifact,

	// Resources
	Consumable,
	Material,

	// Unique
	QuestItem
};

/**
 * 
 */
UCLASS(BlueprintType)
class RPG_API URPGItem : public UObject
{
	GENERATED_BODY()
	
public:
	URPGItem()
		: ItemQuality(EItemQuality::Common)
		, ItemPrice(0)
		, ItemLevel(1)
	{}

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetItemID() const { return ItemID; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetItemName() const { return ItemName; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetItemDescription() const { return ItemDescription; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EItemType GetItemType() const { return ItemType; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EItemQuality GetItemQuality() const { return ItemQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UTexture2D* GetItemImage() const { return ItemImage; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	USkeletalMesh* GetItemMesh() const { return ItemMesh; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetItemPrice() const { return ItemPrice; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetItemLevel() const { return ItemLevel; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsStackable() { return bStackable; }

	bool operator==(URPGItem& other)
	{
		return ItemID == other.ItemID;
	}

protected:
	//UPROPERTY(EditDefaultsOnly)
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	int ItemID;

	UPROPERTY(EditAnywhere)
	FText ItemName;

	UPROPERTY(EditAnywhere)
	FText ItemDescription;

	UPROPERTY(EditAnywhere)
	EItemType ItemType;

	UPROPERTY(VisibleAnywhere)
	EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere)
	class UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere)
	USkeletalMesh* ItemMesh;

	UPROPERTY(EditAnywhere)
	int ItemPrice;

	UPROPERTY(EditAnywhere)
	int ItemLevel;

	UPROPERTY(EditAnywhere)
	bool bStackable;
};
