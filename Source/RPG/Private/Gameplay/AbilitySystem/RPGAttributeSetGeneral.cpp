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
}
