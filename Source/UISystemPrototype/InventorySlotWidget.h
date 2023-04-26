// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "Components/Overlay.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "InventorySystemComponent.h"
#include "DragInventorySlot.h"
#include "DragPreviewWidget.h"
#include "ActionMenuWidget.h"
#include "InventorySlotWidget.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UInventorySlotWidget
 *
 * Author: Jaber A
 *
 * Purpose: Widget for inventory slots
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 09/04/2023    JA          V1.0        Created Widget
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/* Constructor */
	UInventorySlotWidget(const FObjectInitializer& ObjectInitializer);

/* Overriden from UUserWidget */ 
public:
	/* Construct */
	virtual void NativeConstruct() override;

	/* On preview mouse down */
	virtual FReply NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	/* On drag detected */
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	
	/* On drop */
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

public:
	/* Widgets */
	UPROPERTY(meta = (BindWidget))
	class USizeBox* IconSizeBox;

	UPROPERTY(meta = (BindWidget))
	class USizeBox* QuantitySizeBox;

	UPROPERTY(meta = (BindWidget))
	class UButton* SlotButton;

	UPROPERTY(meta = (BindWidget))
	class UBorder* OutsideIconBorder;

	UPROPERTY(meta = (BindWidget))
	class UBorder* InsideIconBorder;

	UPROPERTY(meta = (BindWidget))
	class UBorder* OutsideQuantityBorder;

	UPROPERTY(meta = (BindWidget))
	class UBorder* InsideQuantityBorder;

	UPROPERTY(meta = (BindWidget))
	class UOverlay* ImageOverlay;

	UPROPERTY(meta = (BindWidget))
	class UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* QuantityText;

public:
	UPROPERTY(EditAnywhere)
	FName ItemID; // Item in slots unique ID

	UPROPERTY(EditAnywhere)
	int Quantity; // Quantity of item within the slot

	UPROPERTY(EditAnywhere, Category = "DataTable")
	UDataTable* ItemDataTable; // Item DataTable reference

public:
	int ContentIndex; // Index of item in array

	UInventorySystemComponent* InventorySystemComp; // Reference to inventory system

private:
	TSubclassOf<UUserWidget> DragPreviewWidgetClass; // Class reference to BP 'W_DragPreviewWidget' widget

	TSubclassOf<UUserWidget> ActionMenuWidgetClass; // Class reference to BP 'W_ActionMenu' widget

	UActionMenuWidget* ActionMenu; // Object reference for action menu

	UDragPreviewWidget* DragPreviewWidget; // Reference to Drag Preview Widget

	UDragInventorySlot* DragInventorySlot; // Reference to Drag and Drop operation
};
