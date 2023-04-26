// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/BackgroundBlur.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "InventorySystemComponent.h"
#include "ActionMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEMPROTOTYPE_API UActionMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* Canvas;

	UPROPERTY(meta = (BindWidget))
	class UBackgroundBlur* BackgroundBlur;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* VerticalBox;

	UPROPERTY(meta = (BindWidget))
	class UButton* UseButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* DropButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* DropAllButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* UseText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DropText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DropAllText;

public:
	UInventorySystemComponent* InventorySystemComponent;
	int Index;

public:
	virtual void NativeConstruct() override;

	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent);

	/* Event for use button click */
	UFUNCTION()
	void OnUseButtonClicked();

	/* Event for when drop (single item) button is clicked */
	UFUNCTION()
	void OnDropButtonClicked();

	/* Event for when drop all (whole stack) button is clicked */
	UFUNCTION()
	void OnDropAllButtonClicked();

};
