// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "InventoryGridWidget.h"
#include "PlayerMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEMPROTOTYPE_API UPlayerMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

	UPROPERTY(meta = (BindWidget))
	class UInventoryGridWidget* InventoryGridWidget;

	UPROPERTY()
	TSubclassOf<UInventoryGridWidget> InventoryGridWidgetClass;

public:
	virtual void NativeConstruct() override;

	UPlayerMenuWidget(const FObjectInitializer& ObjectInitializer);

};
