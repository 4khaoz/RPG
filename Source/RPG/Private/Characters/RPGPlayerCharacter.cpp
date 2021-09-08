// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RPGPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Gameplay/AbilitySystem/RPGAttributeSet.h"

ARPGPlayerCharacter::ARPGPlayerCharacter()
{
	BaseTurnRate = 45.f;
	BaseLookRate = 45.f;

	AutoPossessAI = EAutoPossessAI::Disabled;

	// Disable Rotation on Controller Rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Init Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SocketOffset = FVector(0, 0, 150);
	SpringArm->TargetArmLength = 500;
	SpringArm->bUsePawnControlRotation = true;

	// Init Camera Component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
}

void ARPGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARPGPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ARPGPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void ARPGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float ARPGPlayerCharacter::GetMana() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMana();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetMaxMana() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMaxMana();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetStamina() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetStamina();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetMaxStamina() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMaxStamina();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetHunger() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetHunger();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetMaxHunger() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMaxHunger();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetThirst() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetThirst();
	}
	return -1.f;
}

float ARPGPlayerCharacter::GetMaxThirst() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMaxThirst();
	}
	return -1.f;
}

void ARPGPlayerCharacter::MoveForward(const float Value)
{
	if ((GetController() != NULL) && (Value != 0.f))
	{
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ARPGPlayerCharacter::StrafeRight(const float Value)
{
	if ((GetController() != NULL) && (Value != 0.f))
	{
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ARPGPlayerCharacter::TurnCamera(const float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ARPGPlayerCharacter::LookCamera(const float Value)
{
	AddControllerPitchInput(Value * BaseLookRate * GetWorld()->GetDeltaSeconds());
}