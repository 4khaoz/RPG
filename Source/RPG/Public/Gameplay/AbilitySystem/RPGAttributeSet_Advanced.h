// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RPGAttributeSet_Advanced.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * Advanced Attributes
 * like Crit-Stats and Bonus-Damage Modifiers
 */
UCLASS()
class RPG_API URPGAttributeSet_Advanced : public UAttributeSet
{
	GENERATED_BODY()

public:
	URPGAttributeSet_Advanced();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Chance of Critical Hits */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CriticalRate)
	FGameplayAttributeData CriticalRate;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, CriticalRate)

	/* Damage Multiplier of Critical Hits */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CriticalDamage)
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, CriticalDamage)

	/* Damage Multiplier for Physical Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_WeaponMastery)
	FGameplayAttributeData WeaponMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, WeaponMastery)

	/* Damage Multiplier for Pyro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PyroMastery)
	FGameplayAttributeData PyroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PyroMastery)

	/* Damage Multiplier for Hydro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_HydroMastery)
	FGameplayAttributeData HydroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, HydroMastery)

	/* Damage Multiplier for Cryo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CryoMastery)
	FGameplayAttributeData CryoMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, CryoMastery)

	/* Damage Multiplier for Aero Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AeroMastery)
	FGameplayAttributeData AeroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, AeroMastery)

	/* Damage Multiplier for Electro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElectroMastery)
	FGameplayAttributeData ElectroMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, ElectroMastery)

	/* Damage Multiplier for Geo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GeoMastery)
	FGameplayAttributeData GeoMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, GeoMastery)

	/* Damage Multiplier for Light Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LightMastery)
	FGameplayAttributeData LightMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, LightMastery)

	/* Damage Multiplier for Darkness Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DarknessMastery)
	FGameplayAttributeData DarknessMastery;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, DarknessMastery)

	/* Defense ; Scaling Value for Damage-Reduction against all types of Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, Defense)

	/* Reduction Multiplier against Physical Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PhysicalResistance)
	FGameplayAttributeData PhysicalResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PhysicalResistance)

	/* Reduction Multiplier against Pyro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PyroResistance)
	FGameplayAttributeData PyroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PyroResistance)

	/* Reduction Multiplier against Hydro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_HydroResistance)
	FGameplayAttributeData HydroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, HydroResistance)

	/* Reduction Multiplier against Cryo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CryoResistance)
	FGameplayAttributeData CryoResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, CryoResistance)

	/* Reduction Multiplier against Aero Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AeroResistance)
	FGameplayAttributeData AeroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, AeroResistance)

	/* Reduction Multiplier against Electro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElectroResistance)
	FGameplayAttributeData ElectroResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, ElectroResistance)

	/* Reduction Multiplier against Geo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GeoResistance)
	FGameplayAttributeData GeoResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, GeoResistance)

	/* Reduction Multiplier against Light Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LightResistance)
	FGameplayAttributeData LightResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, LightResistance)

	/* Reduction Multiplier against Darkness Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DarknessResistance)
	FGameplayAttributeData DarknessResistance;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, DarknessResistance)

	/**
	Utility Character Stats
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Presence)
	FGameplayAttributeData Presence;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, Presence)

protected:
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

	UFUNCTION()
	virtual void OnRep_Presence(const FGameplayAttributeData& OldPresence);
};
