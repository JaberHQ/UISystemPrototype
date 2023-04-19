// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "PlayerMenuWidget.h"
#include "PlayerHUDWidget.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UPlayerHUDWidget
 *
 * Author: Jaber A
 *
 * Purpose: Player HUD Widget class
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 10/04/2023    JA          V1.0        Created Player HUD Widget class
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

public:
	TSubclassOf<UUserWidget> PlayerMenuWidgetClass; // Reference to BP 'W_PlayerMenu' widget

	UUserWidget* PlayerMenuWidget; // Player Menu Widget

public:
	/* Constructor */
	UPlayerHUDWidget(const FObjectInitializer& ObjectInitializer);

	/* Display inventory menu */
	void DisplayPlayerMenu();

	void ShowContainer(UInventorySystemComponent* containerInventorySystemComponent);

};
