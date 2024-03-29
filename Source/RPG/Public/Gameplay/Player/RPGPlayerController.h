// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARPGPlayerController();

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnRep_PlayerState() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Replicated)
	class URPGInventory* Inventory;

private:
	UFUNCTION(BlueprintCallable)
	void EnableCursorMode();

	UFUNCTION(BlueprintCallable)
	void DisableCursorMode();

	UFUNCTION(BlueprintCallable)
	void SetCursorToCenter();
};
