// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "InventorySystemComponent.h"
#include "DragPreviewWidget.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UDragPreviewWidget
 *
 * Author: Jaber A
 *
 * Purpose: Drag Preview Widget 
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 19/04/2023    JA          V1.0        Created widget for dragging item
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API UDragPreviewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class USizeBox* SizeBox;

	UPROPERTY(meta = (BindWidget))
	class UBorder* Border;

	UPROPERTY(meta = (BindWidget))
	class UImage* Image;

public:
	UPROPERTY(EditAnywhere, Category = "DataTable")
	UDataTable* ItemDataTable; // Reference to itemSlot DataTable

	FName ItemID; // Item ID of slot

public:
	/* Native Construct */
	virtual void NativeConstruct() override;
};
