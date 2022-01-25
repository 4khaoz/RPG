// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RPGAttributeSet_Basic.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * Attributes that can be found on Characters and Items
 */
UCLASS()
class RPG_API URPGAttributeSet_Basic : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	URPGAttributeSet_Basic();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	////////////////////////////////////////////////////////////////////////////////
	// Damage Stats

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, Damage)

	////////////////////////////////////////////////////////////////////////////////
	// Core Attributes

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, Strength)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, Intelligence)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Spirituality)
	FGameplayAttributeData Spirituality;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, Spirituality)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Vitality)
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, Vitality)

	////////////////////////////////////////////////////////////////////////////////
	// CRIT Stats

	/* Chance of Critical Hits */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CriticalRate)
	FGameplayAttributeData CriticalRate;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, CriticalRate)

	/* Damage Multiplier of Critical Hits */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CriticalDamage)
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Basic, CriticalDamage)

protected:
	UFUNCTION()
	virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

	UFUNCTION()
	virtual void OnRep_Strength(const FGameplayAttributeData& OldStrength);

	UFUNCTION()
	virtual void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);

	UFUNCTION()
	virtual void OnRep_Spirituality(const FGameplayAttributeData& OldSpirituality);

	UFUNCTION()
	virtual void OnRep_Vitality(const FGameplayAttributeData& OldVitality);

	UFUNCTION()
	virtual void OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate);

	UFUNCTION()
	virtual void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage);
};
