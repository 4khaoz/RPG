// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RPGBaseCharacter.h"
#include "Gameplay/AbilitySystem/RPGAbilitySystemComponent.h"
#include "Gameplay/AbilitySystem/RPGAttributeSet.h"
#include "Abilities/GameplayAbility.h"

// Sets default values
ARPGBaseCharacter::ARPGBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>(TEXT("AttributeSet"));
}

// Called every frame
void ARPGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ARPGBaseCharacter::bIsAlive() const
{
	return false;
}

float ARPGBaseCharacter::GetCharacterLevel()
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetCharacterLevel();
	}
	return 0.0f;
}

float ARPGBaseCharacter::GetMovementSpeed()
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMovementSpeed();
	}
	return 0.0f;
}

float ARPGBaseCharacter::GetMovementSpeedBaseValue()
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMovementSpeedAttribute().GetGameplayAttributeData(AttributeSet)->GetBaseValue();
	}
	return 0.0f;
}

float ARPGBaseCharacter::GetHealth() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetHealth();
	}
	return -1.f;
}

float ARPGBaseCharacter::GetMaxHealth() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMaxHealth();
	}
	return -1.f;
}

// Called when the game starts or when spawned
void ARPGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitDefaultAttributesAndEffectsOnSpawn();
}

void ARPGBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ARPGBaseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void ARPGBaseCharacter::InitDefaultAttributesAndEffectsOnSpawn()
{
	if (!AbilitySystemComponent || DefaultAttributesAndEffects.IsEmpty())
		return;

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect> GE_Class : DefaultAttributesAndEffects)
	{
		FGameplayEffectSpecHandle EffectSpec = AbilitySystemComponent->MakeOutgoingSpec(GE_Class, 1, EffectContext);
		if (EffectSpec.IsValid())
		{
			FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpec.Data.Get(), AbilitySystemComponent);
		}
	}
}

UAbilitySystemComponent* ARPGBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

URPGAttributeSet* ARPGBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ARPGBaseCharacter::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 AbilityLevel, int32 InputCode)
{
	if (GetLocalRole() == ROLE_Authority && IsValid(AbilitySystemComponent) && IsValid(AbilityClass))
	{
		UGameplayAbility* Ability = AbilityClass->GetDefaultObject<UGameplayAbility>();

		if (IsValid(Ability))
		{
			FGameplayAbilitySpec AbilitySpec(Ability, AbilityLevel, InputCode);

			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
	}
}

void ARPGBaseCharacter::CancelAbility(const FGameplayTagContainer CancelWithTags)
{
	AbilitySystemComponent->CancelAbilities(&CancelWithTags);
}
