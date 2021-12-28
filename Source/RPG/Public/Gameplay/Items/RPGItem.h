// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RPGItem.generated.h"

UENUM(BlueprintType)
enum class EItemQuality : uint8
{
	Common		UMETA(DisplayName = "Common"),	// White Grey
	Uncommon	UMETA(DisplayName = "Uncommon"),	// Green
	Superior	UMETA(DisplayName = "Superior"),	// Blue
	Epic		UMETA(DisplayName = "Epic"),		// Purple
	Masterwork	UMETA(DisplayName = "Masterwork"),	// Pink
	Legendary	UMETA(DisplayName = "Legendary"),	// Yellow Gold
	Legacy		UMETA(DisplayName = "Legacy")		// Red
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon,
	Helmet,
	Armorset,
	Bracelet,
	Ring,
	Earring,
	Necklace,
	Consumable,
	Material
};

/**
 * 
 */
UCLASS()
class RPG_API URPGItem : public UDataAsset
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
	float GetItemWeight() { return ItemWeight; }

protected:
	UPROPERTY(EditDefaultsOnly)
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
	bool bStackable;

	UPROPERTY(EditAnywhere)
	float ItemWeight;

	UPROPERTY(EditAnywhere)
	int ItemLevel;
};
