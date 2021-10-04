// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/AbilitySystem/RPGAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

URPGAttributeSet::URPGAttributeSet()
{

}

void URPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void URPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}
	if (Data.EvaluatedData.Attribute == GetHungerAttribute())
	{
		SetHunger(FMath::Clamp(GetHunger(), 0.f, GetMaxHunger()));
	}
	if (Data.EvaluatedData.Attribute == GetThirstAttribute())
	{
		SetThirst(FMath::Clamp(GetThirst(), 0.f, GetMaxThirst()));
	}
}

void URPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CharacterLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, MaxHunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, MaxThirst, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, AttackDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, SpellPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CriticalRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CriticalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, WeaponMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, PyroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, HydroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CryoMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, AeroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, ElectroMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, GeoMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, LightMastery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, DarknessMastery, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Defense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, PhysicalResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, PyroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, HydroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, CryoResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, AeroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, ElectroResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, GeoResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, LightResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, DarknessResistance, COND_None, REPNOTIFY_Always);


	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Presence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Vitality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet, Spirit, COND_None, REPNOTIFY_Always);
}

void URPGAttributeSet::OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CharacterLevel, OldCharacterLevel);
}

void URPGAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MovementSpeed, OldMovementSpeed);
}

void URPGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Health, OldHealth);
}

void URPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth, OldMaxHealth);
}

void URPGAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Mana, OldMana);
}

void URPGAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxMana, OldMaxMana);
}

void URPGAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Stamina, OldStamina);
}

void URPGAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxStamina, OldMaxStamina);
}

void URPGAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Hunger, OldHunger);
}

void URPGAttributeSet::OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHunger, OldMaxHunger);
}

void URPGAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Thirst, OldThirst);
}

void URPGAttributeSet::OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxThirst, OldMaxThirst);
}

void URPGAttributeSet::OnRep_AttackDamage(const FGameplayAttributeData& OldAttackDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage, OldAttackDamage);
}

void URPGAttributeSet::OnRep_SpellPower(const FGameplayAttributeData& OldSpellPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SpellPower, OldSpellPower);
}

void URPGAttributeSet::OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CriticalRate, OldCriticalRate);
}

void URPGAttributeSet::OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CriticalDamage, OldCriticalDamage);
}

void URPGAttributeSet::OnRep_WeaponMastery(const FGameplayAttributeData& OldWeaponMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, WeaponMastery, OldWeaponMastery);
}

void URPGAttributeSet::OnRep_PyroMastery(const FGameplayAttributeData& OldPyroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PyroMastery, OldPyroMastery);
}

void URPGAttributeSet::OnRep_HydroMastery(const FGameplayAttributeData& OldHydroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, HydroMastery, OldHydroMastery);
}

void URPGAttributeSet::OnRep_CryoMastery(const FGameplayAttributeData& OldCryoMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CryoMastery, OldCryoMastery);
}

void URPGAttributeSet::OnRep_AeroMastery(const FGameplayAttributeData& OldAeroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AeroMastery, OldAeroMastery);
}

void URPGAttributeSet::OnRep_ElectroMastery(const FGameplayAttributeData& OldElectroMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectroMastery, OldElectroMastery);
}

void URPGAttributeSet::OnRep_GeoMastery(const FGameplayAttributeData& OldGeoMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, GeoMastery, OldGeoMastery);
}

void URPGAttributeSet::OnRep_LightMastery(const FGameplayAttributeData& OldLightMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, LightMastery, OldLightMastery);
}

void URPGAttributeSet::OnRep_DarknessMastery(const FGameplayAttributeData& OldDarknessMastery)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DarknessMastery, OldDarknessMastery);
}

void URPGAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Defense, OldDefense);
}

void URPGAttributeSet::OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalResistance, OldPhysicalResistance);
}

void URPGAttributeSet::OnRep_PyroResistance(const FGameplayAttributeData& OldPyroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PyroResistance, OldPyroResistance);
}

void URPGAttributeSet::OnRep_HydroResistance(const FGameplayAttributeData& OldHydroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, HydroResistance, OldHydroResistance);
}

void URPGAttributeSet::OnRep_CryoResistance(const FGameplayAttributeData& OldCryoResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CryoResistance, OldCryoResistance);
}

void URPGAttributeSet::OnRep_AeroResistance(const FGameplayAttributeData& OldAeroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AeroResistance, OldAeroResistance);
}

void URPGAttributeSet::OnRep_ElectroResistance(const FGameplayAttributeData& OldElectroResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectroResistance, OldElectroResistance);
}

void URPGAttributeSet::OnRep_GeoResistance(const FGameplayAttributeData& OldGeoResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, GeoResistance, OldGeoResistance);
}

void URPGAttributeSet::OnRep_LightResistance(const FGameplayAttributeData& OldLightResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, LightResistance, OldLightResistance);
}

void URPGAttributeSet::OnRep_DarknessResistance(const FGameplayAttributeData& OldDarknessResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DarknessResistance, OldDarknessResistance);
}

void URPGAttributeSet::OnRep_Presence(const FGameplayAttributeData& OldPresence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Presence, OldPresence);
}

void URPGAttributeSet::OnRep_Vitality(const FGameplayAttributeData& OldVitality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Vitality, OldVitality);
}

void URPGAttributeSet::OnRep_Spirit(const FGameplayAttributeData& OldSpirit)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Spirit, OldSpirit);
}
