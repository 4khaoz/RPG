// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Player/RPGPlayerState.h"
#include "Gameplay/AbilitySystem/RPGAbilitySystemComponent.h"
#include "Gameplay/AbilitySystem/RPGAttributeSetGeneral.h"
#include "Gameplay/AbilitySystem/RPGAttributeSetAdvanced.h"

ARPGPlayerState::ARPGPlayerState()
{
	ASC = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ASC->SetIsReplicated(true);
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttrSetGeneral = CreateDefaultSubobject<URPGAttributeSetGeneral>(TEXT("AttributeSetGeneral"));
	AttrSetAdvanced = CreateDefaultSubobject<URPGAttributeSetAdvanced>(TEXT("AttributeSetAdvanced"));
}

UAbilitySystemComponent* ARPGPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}

URPGAttributeSetGeneral* ARPGPlayerState::GetAttributeSetGeneral() const
{
	return AttrSetGeneral;
}

URPGAttributeSetAdvanced* ARPGPlayerState::GetAttributeSetAdvanced() const
{
	return AttrSetAdvanced;
}

float ARPGPlayerState::GetHealth() const
{
	return AttrSetGeneral->GetHealth();
}

float ARPGPlayerState::GetMaxHealth() const
{
	return AttrSetGeneral->GetMaxHealth();
}

float ARPGPlayerState::GetMana() const
{
	return AttrSetGeneral->GetMana();
}

float ARPGPlayerState::GetMaxMana() const
{
	return AttrSetGeneral->GetMaxMana();
}

float ARPGPlayerState::GetStamina() const
{
	return AttrSetGeneral->GetStamina();
}

float ARPGPlayerState::GetMaxStamina() const
{
	return AttrSetGeneral->GetMaxStamina();
}

float ARPGPlayerState::GetHunger() const
{
	return AttrSetGeneral->GetHunger();
}

float ARPGPlayerState::GetMaxHunger() const
{
	return AttrSetGeneral->GetMaxHunger();
}

float ARPGPlayerState::GetThirst() const
{
	return AttrSetGeneral->GetThirst();
}

float ARPGPlayerState::GetMaxThirst() const
{
	return AttrSetGeneral->GetMaxThirst();
}
