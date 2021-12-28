// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/AbilitySystem/RPGAttributeSet_Basic.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

URPGAttributeSet_Basic::URPGAttributeSet_Basic()
{

}

void URPGAttributeSet_Basic::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
}

void URPGAttributeSet_Basic::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}

void URPGAttributeSet_Basic::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
}

void URPGAttributeSet_Basic::OnRep_PowerLevel(const FGameplayAttributeData& OldPowerLevel)
{

}

void URPGAttributeSet_Basic::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
}

void URPGAttributeSet_Basic::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
}

void URPGAttributeSet_Basic::OnRep_Spirituality(const FGameplayAttributeData& OldSpirituality)
{
}

void URPGAttributeSet_Basic::OnRep_Vitality(const FGameplayAttributeData& OldVitality)
{
}
