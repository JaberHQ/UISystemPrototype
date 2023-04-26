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

public:
	/* Constructor */
	APlayerControllerFPS();

public:
	/** Inventory Mapping Context **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InventoryMappingContext;

	/** Inventory Input Action **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventoryAction;

	UPlayerHUDWidget* PlayerHUDWidget; // Object reference to playerHUD widget 

protected:
	/* Begin play */
	virtual void BeginPlay() override;

private:
	TSubclassOf<UPlayerHUDWidget> PlayerHudWidgetClass; // Class reference to BP 'W_PlayerHUD' class

private:
	/* Function when inventory action is pressed */
	void InventoryActionPressed();

};
