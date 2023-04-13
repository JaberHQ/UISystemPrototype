// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "InventoryGridWidget.h"
#include "PlayerMenuWidget.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UPlayerMenuWidget
 *
 * Author: Jaber A
 *
 * Purpose: Widget for Player menu
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 09/04/2023    JA          V1.0        Created Widget
*****************************************************************************/
UCLASS()
class UISYSTEMPROTOTYPE_API UPlayerMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

	UPROPERTY(meta = (BindWidget))
	class UInventoryGridWidget* InventoryGridWidget;

public:
	/* Native Construct */
	virtual void NativeConstruct() override;


};
