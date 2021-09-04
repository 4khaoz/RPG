// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/AbilitySystem/RPGAttributeSetGeneral.h"
#include "GameplayEffect.h"
#include "Net/UnrealNetwork.h"

URPGAttributeSetGeneral::URPGAttributeSetGeneral()
{

}

void URPGAttributeSetGeneral::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void URPGAttributeSetGeneral::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void URPGAttributeSetGeneral::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, MaxHunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSetGeneral, MaxThirst, COND_None, REPNOTIFY_Always);
}

void URPGAttributeSetGeneral::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, Health, OldHealth);
}

void URPGAttributeSetGeneral::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, MaxHealth, OldMaxHealth);
}

void URPGAttributeSetGeneral::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, Mana, OldMana);
}

void URPGAttributeSetGeneral::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, MaxMana, OldMaxMana);
}

void URPGAttributeSetGeneral::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, Stamina, OldStamina);
}

void URPGAttributeSetGeneral::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, MaxStamina, OldMaxStamina);
}

void URPGAttributeSetGeneral::OnRep_Hunger(const FGameplayAttributeData& OldHunger)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, Hunger, OldHunger);
}

void URPGAttributeSetGeneral::OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, MaxHunger, OldMaxHunger);
}

void URPGAttributeSetGeneral::OnRep_Thirst(const FGameplayAttributeData& OldThirst)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, Thirst, OldThirst);
}

void URPGAttributeSetGeneral::OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSetGeneral, MaxThirst, OldMaxThirst);
}
