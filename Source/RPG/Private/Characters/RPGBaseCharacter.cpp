// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RPGBaseCharacter.h"

// Sets default values
ARPGBaseCharacter::ARPGBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
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
