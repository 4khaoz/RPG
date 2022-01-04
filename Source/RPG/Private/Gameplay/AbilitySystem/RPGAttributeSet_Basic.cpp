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
	Super::PreAttributeChange(Attribute, NewValue);
}

void URPGAttributeSet_Basic::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void URPGAttributeSet_Basic::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, Spirituality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, Vitality, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, CriticalRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URPGAttributeSet_Basic, CriticalDamage, COND_None, REPNOTIFY_Always);
}

void URPGAttributeSet_Basic::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, Damage, OldDamage);
}

void URPGAttributeSet_Basic::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, Strength, OldStrength);
}

void URPGAttributeSet_Basic::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, Intelligence, OldIntelligence);
}

void URPGAttributeSet_Basic::OnRep_Spirituality(const FGameplayAttributeData& OldSpirituality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, Spirituality, OldSpirituality);
}

void URPGAttributeSet_Basic::OnRep_Vitality(const FGameplayAttributeData& OldVitality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, Vitality, OldVitality);
}

void URPGAttributeSet_Basic::OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, CriticalRate, OldCriticalRate);
}

void URPGAttributeSet_Basic::OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet_Basic, CriticalDamage, OldCriticalDamage);
}
