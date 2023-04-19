// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "Components/Border.h"
#include "Components/WrapBox.h"
#include "InventorySystemComponent.h"
#include "InventorySlotWidget.h"
#include "InventoryGridWidget.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UInventoryGridWidget
 *
 * Author: Jaber A
 *
 * Purpose: Widget for inventory grid
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 09/04/2023    JA          V1.0        Created Widget
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API UInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UBorder* Border;

	UPROPERTY(meta = (BindWidget))
	class UScrollBox* ScrollBox;

	UPROPERTY(meta = (BindWidget))
	class UWrapBox* GridBox;
	
public:
	UInventorySlotWidget* InventorySlotWidget;

	UInventorySystemComponent* InventorySystemComp;

	TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;


public:
	/* Constructor */
	UInventoryGridWidget(const FObjectInitializer& ObjectInitializer);

	/* Native Construct */
	virtual void NativeConstruct() override;

	/* Display Inventory On Screen */
	void DisplayInventory(UInventorySystemComponent* inventorySystemComp);

	/* Create the amount of slots necessary for the inventory */
	void ConstructInventoryGrid(UInventorySystemComponent* inventorySystemComp);

	/* FOnInventoryUpdate delegate Function */
	UFUNCTION()
	void UpdatedInventory();
};
