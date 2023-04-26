// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "InventoryGridWidget.h"
#include "InventorySystemComponent.h"
#include "ContainerInventoryWidget.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UContainerInventoryWidget
 *
 * Author: Jaber A
 *
 * Purpose: Widget for the Container inventory Menu
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 26/04/2023    JA          V1.0        Created Widget
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API UContainerInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

/* Overriden from UUserWidget*/
public:
	/* Construct */
	virtual void NativeConstruct() override;

	/* Destruct */
	virtual void NativeDestruct() override;

	/* On Key Down - checks if player has pressed a certain keyboard input */
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

/* UMG Components */
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

	UPROPERTY(meta = (BindWidget))
	class UInventoryGridWidget* PlayerInventory;

	UPROPERTY(meta = (BindWidget))
	class UInventoryGridWidget* ContainerInventory;

public:
	UInventorySystemComponent* ContainerInventorySystemComponent;



};
