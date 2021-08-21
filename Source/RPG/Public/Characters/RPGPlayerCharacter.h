// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RPGBaseCharacter.h"
#include "RPGPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerCharacter : public ARPGBaseCharacter
{
	GENERATED_BODY()

	ARPGPlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	/* Camera Components */
	UPROPERTY(BlueprintReadOnly)
	class USpringArmComponent* SpringArm;
	UPROPERTY(BlueprintReadOnly)
	class UCameraComponent* Camera;

	/* Character Movement Functions */
	UFUNCTION(BlueprintCallable)
	void MoveForward(const float Value);
	UFUNCTION(BlueprintCallable)
	void StrafeRight(const float Value);

	/* Camera Movement Functions */
	UFUNCTION(BlueprintCallable)
	void TurnCamera(const float Value);
	UFUNCTION(BlueprintCallable)
	void LookCamera(const float Value);

private:
	float BaseTurnRate;
	float BaseLookRate;
};