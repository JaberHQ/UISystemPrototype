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

private:

public:
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

	UPROPERTY(EditAnywhere)
	FName ItemID;

	UPROPERTY(EditAnywhere)
	int Quantity;

	UPROPERTY(EditAnywhere, Category = "DataTable")
	UDataTable* ItemDataTable;

	class UInventorySystemComponent* InventorySystemComp; 

public:
	/* Native Construct */
	virtual void NativeConstruct() override;

};
