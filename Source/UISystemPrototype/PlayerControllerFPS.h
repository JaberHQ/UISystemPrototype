// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerHUDWidget.h"
#include "PlayerControllerFPS.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: APlayerControllerFPS
 *
 * Author: Jaber A
 *
 * Purpose: Player controller class
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 10/04/2023    JA          V1.0        Created Player controller class
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API APlayerControllerFPS : public APlayerController
{
	GENERATED_BODY()
	
private:
	/* Function when inventory action is pressed */
	void InventoryActionPressed();

protected:
	/* Begin play */
	virtual void BeginPlay() override;

public:
	/** Inventory Mapping Context **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InventoryMappingContext;

	/** Inventory Input Action **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventoryAction;

	TSubclassOf<UPlayerHUDWidget> PlayerHudWidgetClass; // Reference to BP 'W_PlayerHUD' class

	UPlayerHUDWidget* PlayerHUDWidget; // Reference to playerHUD widget 

public:
	/* Constructor */
	APlayerControllerFPS();
};
