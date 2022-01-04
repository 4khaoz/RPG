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

	////////////////////////////////////////////////////////////////////////////////
	// Physical Damage Multiplier

	/* Damage Multiplier for Physical Damage done with Sword, Dagger and Spear */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TechniqueBonusDamage)
	FGameplayAttributeData TechniqueBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, TechniqueBonusDamage)

	/* Damage Multiplier for Physical Damage done with Greatsword, Battleaxe and Warhammer */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PowerBonusDamage)
	FGameplayAttributeData PowerBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PowerBonusDamage)

	/* Damage Multiplier for Physical Damage done with Bow, Rifle and Cannon */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PrecisionBonusDamage)
	FGameplayAttributeData PrecisionBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PrecisionBonusDamage)

	////////////////////////////////////////////////////////////////////////////////
	// Magical Damage Multiplier Stats

	/* Damage Multiplier for Pyro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PyroBonusDamage)
	FGameplayAttributeData PyroBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PyroBonusDamage)

	/* Damage Multiplier for Hydro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_HydroBonusDamage)
	FGameplayAttributeData HydroBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, HydroBonusDamage)

	/* Damage Multiplier for Cryo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CryoBonusDamage)
	FGameplayAttributeData CryoBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, CryoBonusDamage)

	/* Damage Multiplier for Aero Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AeroBonusDamage)
	FGameplayAttributeData AeroBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, AeroBonusDamage)

	/* Damage Multiplier for Electro Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElectroBonusDamage)
	FGameplayAttributeData ElectroBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, ElectroBonusDamage)

	/* Damage Multiplier for Geo Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GeoBonusDamage)
	FGameplayAttributeData GeoBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, GeoBonusDamage)

	/* Damage Multiplier for Light Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LightBonusDamage)
	FGameplayAttributeData LightBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, LightBonusDamage)

	/* Damage Multiplier for Darkness Damage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DarknessBonusDamage)
	FGameplayAttributeData DarknessBonusDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, DarknessBonusDamage)

	////////////////////////////////////////////////////////////////////////////////
	// CRIT Stats

	/* Reduction Multiplier against Physical Damage done with Sword, Dagger and Spear */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TechniqueResistance)
	FGameplayAttributeData TechniqueDefense;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, TechniqueResistance)

	/* Reduction Multiplier against Physical Damage done with Greatsword, Battleaxe and Warhammer */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PowerDefense)
	FGameplayAttributeData PowerDefense;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PowerDefense)

	/* Reduction Multiplier against Physical Damage done with Bow, Rifle and Cannon */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PrecisionDefense)
	FGameplayAttributeData PrecisionDefense;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, PrecisionDefense)

	////////////////////////////////////////////////////////////////////////////////
	// CRIT Stats

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



	/* Increase Aggro-Generation */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Presence)
	FGameplayAttributeData Presence;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet_Advanced, Presence)

protected:
	UFUNCTION()
	virtual void OnRep_TechniqueBonusDamage(const FGameplayAttributeData& OldTechniqueBonusDamage);

	UFUNCTION()
	virtual void OnRep_PowerBonusDamage(const FGameplayAttributeData& OldPowerBonusDamage);

	UFUNCTION()
	virtual void OnRep_PrecisionBonusDamage(const FGameplayAttributeData& OldPrecisionBonusDamage);

	UFUNCTION()
	virtual void OnRep_PyroBonusDamage(const FGameplayAttributeData& OldPyroBonusDamage);

	UFUNCTION()
	virtual void OnRep_HydroBonusDamage(const FGameplayAttributeData& OldHydroBonusDamage);

	UFUNCTION()
	virtual void OnRep_CryoBonusDamage(const FGameplayAttributeData& OldCryoBonusDamage);

	UFUNCTION()
	virtual void OnRep_AeroBonusDamage(const FGameplayAttributeData& OldAeroBonusDamage);

	UFUNCTION()
	virtual void OnRep_ElectroBonusDamage(const FGameplayAttributeData& OldElectroBonusDamage);

	UFUNCTION()
	virtual void OnRep_GeoBonusDamage(const FGameplayAttributeData& OldGeoBonusDamage);

	UFUNCTION()
	virtual void OnRep_LightBonusDamage(const FGameplayAttributeData& OldLightBonusDamage);

	UFUNCTION()
	virtual void OnRep_DarknessBonusDamage(const FGameplayAttributeData& OldDarknessBonusDamage);

	UFUNCTION()
	virtual void OnRep_TechniqueDefense(const FGameplayAttributeData& OldTechniqueDefense);

	UFUNCTION()
	virtual void OnRep_PowerDefense(const FGameplayAttributeData& OldPowerDefense);

	UFUNCTION()
	virtual void OnRep_PrecisionDefense(const FGameplayAttributeData& OldPrecisionDefense);

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
