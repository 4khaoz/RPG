// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/AbilitySystem/RPGAttributeSet_Advanced.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

URPGAttributeSet_Advanced::URPGAttributeSet_Advanced()
{

}

void URPGAttributeSet_Advanced::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void URPGAttributeSet_Advanced::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void URPGAttributeSet_Advanced::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, TechniqueBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PowerBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PrecisionBonusDamage, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PyroBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, HydroBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, CryoBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, AeroBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, ElectroBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, GeoBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, LightBonusDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, DarknessBonusDamage, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, TechniqueDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PowerDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PrecisionDefense, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PyroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, HydroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, CryoResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, AeroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, ElectroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, GeoResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, LightResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, DarknessResistance, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, Presence, COND_None, REPNOTIFY_Always);
}

void URPGAttributeSet_Advanced::OnRep_TechniqueBonusDamage(const FGameplayAttributeData& OldTechniqueBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, TechniqueBonusDamage, OldTechniqueBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_PowerBonusDamage(const FGameplayAttributeData& OldPowerBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PowerBonusDamage, OldPowerBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_PrecisionBonusDamage(const FGameplayAttributeData& OldPrecisionBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PrecisionBonusDamage, OldPrecisionBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_PyroBonusDamage(const FGameplayAttributeData& OldPyroBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PyroBonusDamage, OldPyroBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_HydroBonusDamage(const FGameplayAttributeData& OldHydroBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, HydroBonusDamage, OldHydroBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_CryoBonusDamage(const FGameplayAttributeData& OldCryoBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, CryoBonusDamage, OldCryoBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_AeroBonusDamage(const FGameplayAttributeData& OldAeroBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, AeroBonusDamage, OldAeroBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_ElectroBonusDamage(const FGameplayAttributeData& OldElectroBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, ElectroBonusDamage, OldElectroBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_GeoBonusDamage(const FGameplayAttributeData& OldGeoBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, GeoBonusDamage, OldGeoBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_LightBonusDamage(const FGameplayAttributeData& OldLightBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, LightBonusDamage, OldLightBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_DarknessBonusDamage(const FGameplayAttributeData& OldDarknessBonusDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, DarknessBonusDamage, OldDarknessBonusDamage);
}

void URPGAttributeSet_Advanced::OnRep_TechniqueDefense(const FGameplayAttributeData& OldTechniqueDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, TechniqueDefense, OldTechniqueDefense);
}

void URPGAttributeSet_Advanced::OnRep_PowerDefense(const FGameplayAttributeData& OldPowerDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PowerDefense, OldPowerDefense);
}

void URPGAttributeSet_Advanced::OnRep_PrecisionDefense(const FGameplayAttributeData& OldPrecisionDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PrecisionDefense, OldPrecisionDefense);
}

void URPGAttributeSet_Advanced::OnRep_PyroResistance(const FGameplayAttributeData& OldPyroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PyroResistance, OldPyroResistance);
}

void URPGAttributeSet_Advanced::OnRep_HydroResistance(const FGameplayAttributeData& OldHydroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, HydroResistance, OldHydroResistance);
}

void URPGAttributeSet_Advanced::OnRep_CryoResistance(const FGameplayAttributeData& OldCryoResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, CryoResistance, OldCryoResistance);
}

void URPGAttributeSet_Advanced::OnRep_AeroResistance(const FGameplayAttributeData& OldAeroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, AeroResistance, OldAeroResistance);
}

void URPGAttributeSet_Advanced::OnRep_ElectroResistance(const FGameplayAttributeData& OldElectroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, ElectroResistance, OldElectroResistance);
}

void URPGAttributeSet_Advanced::OnRep_GeoResistance(const FGameplayAttributeData& OldGeoResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, GeoResistance, OldGeoResistance);
}

void URPGAttributeSet_Advanced::OnRep_LightResistance(const FGameplayAttributeData& OldLightResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, LightResistance, OldLightResistance);
}

void URPGAttributeSet_Advanced::OnRep_DarknessResistance(const FGameplayAttributeData& OldDarknessResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, DarknessResistance, OldDarknessResistance);
}

void URPGAttributeSet_Advanced::OnRep_Presence(const FGameplayAttributeData& OldPresence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, Presence, OldPresence);
}
