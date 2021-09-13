// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RPGAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class RPG_API URPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	URPGAttributeSet();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Character Level */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CharacterLevel)
	FGameplayAttributeData CharacterLevel;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CharacterLevel)

	/* Character Movement Speed */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MovementSpeed)
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MovementSpeed)

	/* Current Health ; Death expected if Health = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Health)

	/* Maximum Health */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth)

	/* Current Mana ; Resource to use Abilities */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mana)

	/* Maximum Mana */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxMana)

	/* Current Stamina ; Resource to Sprint and Dash */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Stamina)

	/* Maximum Stamina */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxStamina)

	/* Current Hunger ; Starvation-Effect expected if Hunger = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Hunger)
	FGameplayAttributeData Hunger;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Hunger)

	/* Maximum Hunger */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHunger)
	FGameplayAttributeData MaxHunger;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHunger)

	/* Current Thirst ; Dehydration-Effect expected if Thirst = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Thirst)
	FGameplayAttributeData Thirst;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Thirst)

	/* Maximum Thirst*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxThirst)
	FGameplayAttributeData MaxThirst;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxThirst)

	/* Attack Damage ; Scaling Value for Abilities of Type "Skill" */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackDamage)
	FGameplayAttributeData AttackDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage)

	/* Spell Power ; Scaling Value for Abilities of Type "Spell" */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_SpellPower)
	FGameplayAttributeData SpellPower;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SpellPower)

	/* Chance of Critical Hits */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CriticalRate)
	FGameplayAttributeData CriticalRate;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CriticalRate)

	/* Damage Multiplier of Critical Hits */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CriticalDamage)
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CriticalDamage)

	/* Damage Multiplier for Physical Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_WeaponMastery)
	FGameplayAttributeData WeaponMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, WeaponMastery)

	/* Damage Multiplier for Pyro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PyroMastery)
	FGameplayAttributeData PyroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PyroMastery)

	/* Damage Multiplier for Hydro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_HydroMastery)
	FGameplayAttributeData HydroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, HydroMastery)

	/* Damage Multiplier for Cryo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CryoMastery)
	FGameplayAttributeData CryoMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CryoMastery)

	/* Damage Multiplier for Aero Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AeroMastery)
	FGameplayAttributeData AeroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AeroMastery)

	/* Damage Multiplier for Electro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElectroMastery)
	FGameplayAttributeData ElectroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectroMastery)

	/* Damage Multiplier for Geo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GeoMastery)
	FGameplayAttributeData GeoMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, GeoMastery)

	/* Damage Multiplier for Light Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LightMastery)
	FGameplayAttributeData LightMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightMastery)

	/* Damage Multiplier for Darkness Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DarknessMastery)
	FGameplayAttributeData DarknessMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DarknessMastery)

	/* Defense ; Scaling Value for Damage-Reduction against all types of Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Defense)

	/* Reduction Multiplier against Physical Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PhysicalResistance)
	FGameplayAttributeData PhysicalResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalResistance)

	/* Reduction Multiplier against Pyro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PyroResistance)
	FGameplayAttributeData PyroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PyroResistance)

	/* Reduction Multiplier against Hydro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_HydroResistance)
	FGameplayAttributeData HydroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, HydroResistance)

	/* Reduction Multiplier against Cryo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CryoResistance)
	FGameplayAttributeData CryoResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CryoResistance)

	/* Reduction Multiplier against Aero Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AeroResistance)
	FGameplayAttributeData AeroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AeroResistance)

	/* Reduction Multiplier against Electro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElectroResistance)
	FGameplayAttributeData ElectroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectroResistance)

	/* Reduction Multiplier against Geo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GeoResistance)
	FGameplayAttributeData GeoResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, GeoResistance)

	/* Reduction Multiplier against Light Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LightResistance)
	FGameplayAttributeData LightResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightResistance)

	/* Reduction Multiplier against Darkness Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DarknessResistance)
	FGameplayAttributeData DarknessResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DarknessResistance)

	/**
	Utility Character Stats
	*/
	FGameplayAttributeData Presence;
	FGameplayAttributeData Toughness;
	FGameplayAttributeData Endurance;
	FGameplayAttributeData Vitality;
	FGameplayAttributeData Spirit;

protected:
	/**
	OnRep functions for GameplayAttributes
	*/
	UFUNCTION()
	virtual void OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel);

	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);
	
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);

	UFUNCTION()
	virtual void OnRep_Hunger(const FGameplayAttributeData& OldHunger);

	UFUNCTION()
	virtual void OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger);

	UFUNCTION()
	virtual void OnRep_Thirst(const FGameplayAttributeData& OldThirst);

	UFUNCTION()
	virtual void OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst);

	UFUNCTION()
	virtual void OnRep_AttackDamage(const FGameplayAttributeData& OldAttackDamage);

	UFUNCTION()
	virtual void OnRep_SpellPower(const FGameplayAttributeData& OldSpellPower);

	UFUNCTION()
	virtual void OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate);

	UFUNCTION()
	virtual void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage);

	UFUNCTION()
	virtual void OnRep_WeaponMastery(const FGameplayAttributeData& OldWeaponMastery);
	
	UFUNCTION()
	virtual void OnRep_PyroMastery(const FGameplayAttributeData& OldPyroMastery);
	
	UFUNCTION()
	virtual void OnRep_HydroMastery(const FGameplayAttributeData& OldHydroMastery);
	
	UFUNCTION()
	virtual void OnRep_CryoMastery(const FGameplayAttributeData& OldCryoMastery);
	
	UFUNCTION()
	virtual void OnRep_AeroMastery(const FGameplayAttributeData& OldAeroMastery);
	
	UFUNCTION()
	virtual void OnRep_ElectroMastery(const FGameplayAttributeData& OldElectroMastery);
	
	UFUNCTION()
	virtual void OnRep_GeoMastery(const FGameplayAttributeData& OldGeoMastery);
	
	UFUNCTION()
	virtual void OnRep_LightMastery(const FGameplayAttributeData& OldLightMastery);

	UFUNCTION()
	virtual void OnRep_DarknessMastery(const FGameplayAttributeData& OldDarknessMastery);

	UFUNCTION()
	virtual void OnRep_Defense(const FGameplayAttributeData& OldDefense);

	UFUNCTION()
	virtual void OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance);

	UFUNCTION()
	virtual void OnRep_PyroResistance(const FGameplayAttributeData& OldPyroResistance);

	UFUNCTION()
	virtual void OnRep_HydroResistance(const FGameplayAttributeData& OldHydroResistance);

	UFUNCTION()
	virtual void OnRep_CryoResistance(const FGameplayAttributeData& OldCryoResistance);

	UFUNCTION()
	virtual void OnRep_AeroResistance(const FGameplayAttributeData& OldAeroResistance);

	UFUNCTION()
	virtual void OnRep_ElectroResistance(const FGameplayAttributeData& OldElectroResistance);

	UFUNCTION()
	virtual void OnRep_GeoResistance(const FGameplayAttributeData& OldGeoResistance);

	UFUNCTION()
	virtual void OnRep_LightResistance(const FGameplayAttributeData& OldLightResistance);

	UFUNCTION()
	virtual void OnRep_DarknessResistance(const FGameplayAttributeData& OldDarknessResistance);
};
