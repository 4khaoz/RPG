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

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, CriticalRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, CriticalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, WeaponMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PyroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, HydroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, CryoMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, AeroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, ElectroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, GeoMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, LightMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, DarknessMastery, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, Defense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Advanced, PhysicalResistance, COND_None, REPNOTIFY_Always);
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

void URPGAttributeSet_Advanced::OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, CriticalRate, OldCriticalRate);
}

void URPGAttributeSet_Advanced::OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, CriticalDamage, OldCriticalDamage);
}

void URPGAttributeSet_Advanced::OnRep_WeaponMastery(const FGameplayAttributeData& OldWeaponMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, WeaponMastery, OldWeaponMastery);
}

void URPGAttributeSet_Advanced::OnRep_PyroMastery(const FGameplayAttributeData& OldPyroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PyroMastery, OldPyroMastery);
}

void URPGAttributeSet_Advanced::OnRep_HydroMastery(const FGameplayAttributeData& OldHydroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, HydroMastery, OldHydroMastery);
}

void URPGAttributeSet_Advanced::OnRep_CryoMastery(const FGameplayAttributeData& OldCryoMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, CryoMastery, OldCryoMastery);
}

void URPGAttributeSet_Advanced::OnRep_AeroMastery(const FGameplayAttributeData& OldAeroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, AeroMastery, OldAeroMastery);
}

void URPGAttributeSet_Advanced::OnRep_ElectroMastery(const FGameplayAttributeData& OldElectroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, ElectroMastery, OldElectroMastery);
}

void URPGAttributeSet_Advanced::OnRep_GeoMastery(const FGameplayAttributeData& OldGeoMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, GeoMastery, OldGeoMastery);
}

void URPGAttributeSet_Advanced::OnRep_LightMastery(const FGameplayAttributeData& OldLightMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, LightMastery, OldLightMastery);
}

void URPGAttributeSet_Advanced::OnRep_DarknessMastery(const FGameplayAttributeData& OldDarknessMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, DarknessMastery, OldDarknessMastery);
}

void URPGAttributeSet_Advanced::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, Defense, OldDefense);
}

void URPGAttributeSet_Advanced::OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Advanced, PhysicalResistance, OldPhysicalResistance);
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
