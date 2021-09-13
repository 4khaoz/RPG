// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "RPGBaseCharacter.generated.h"

UCLASS()
class RPG_API ARPGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGBaseCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Returns true if Health > 0.f
	bool bIsAlive() const;

	/**
	Implement IAbilitySystemInterface
	*/
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class URPGAttributeSet* GetAttributeSet() const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GrantAbility(TSubclassOf<class UGameplayAbility> AbilityClass, int32 AbilityLevel, int32 InputCode);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void CancelAbility(const FGameplayTagContainer CancelWithTags);

	/**
	Getters for Attributes every Character has
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCharacterLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMovementSpeed();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMovementSpeedBaseValue();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxHealth() const;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	void InitDefaultAttributesAndEffectsOnSpawn();

	/**
	Gameplay Ability System
	*/
	UPROPERTY()
	class URPGAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class URPGAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> DefaultAttributesAndEffects;
};
