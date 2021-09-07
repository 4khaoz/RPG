// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "RPGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ARPGPlayerState();

	/**
	Implement IAbilitySystemInterface
	*/
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class URPGAttributeSetGeneral* GetAttributeSetGeneral() const;
	class URPGAttributeSetAdvanced* GetAttributeSetAdvanced() const;

	/**
	Getters for Attributes
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealth() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxHealth() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMana() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxMana() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetStamina() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxStamina() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHunger() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxHunger() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetThirst() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxThirst() const;

protected:
	/**
	Gameplay Ability System
	*/
	UPROPERTY()
	class URPGAbilitySystemComponent* ASC;

	UPROPERTY()
	class URPGAttributeSetGeneral* AttrSetGeneral;

	UPROPERTY()
	class URPGAttributeSetAdvanced* AttrSetAdvanced;
};
