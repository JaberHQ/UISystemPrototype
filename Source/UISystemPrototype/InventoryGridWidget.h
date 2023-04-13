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

/**
 * 
 */
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
	
	UPROPERTY()
	class UInventorySlotWidget* InventorySlotWidget;

	UPROPERTY()
	class UInventorySystemComponent* InventorySystemComp;

	UPROPERTY()
		TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;

public:
	virtual void NativeConstruct() override;

	void DisplayInventory(UInventorySystemComponent* inventorySystemComp);

	UInventoryGridWidget(const FObjectInitializer& ObjectInitializer);

};
