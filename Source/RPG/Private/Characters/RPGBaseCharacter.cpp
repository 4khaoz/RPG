// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RPGBaseCharacter.h"
#include "Gameplay/AbilitySystem/RPGAbilitySystemComponent.h"
#include "Gameplay/AbilitySystem/RPGAttributeSet.h"

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
	
}

void ARPGBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ARPGBaseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

UAbilitySystemComponent* ARPGBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

URPGAttributeSet* ARPGBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ARPGBaseCharacter::GrantAbility()
{
}

void ARPGBaseCharacter::CancelAbility(const FGameplayTagContainer CancelWithTags)
{
	AbilitySystemComponent->CancelAbilities(&CancelWithTags);
}
