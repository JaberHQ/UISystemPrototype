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
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UBorder* Border;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UScrollBox* ScrollBox;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UWrapBox* GridBox;
	
	UPROPERTY(EditAnywhere)
	UInventorySlotWidget* InventorySlotWidget;

	UInventorySystemComponent* InventorySystemComp;

public:
	virtual void NativePreConstruct() override;

	void DisplayInventory(UInventorySystemComponent* inventorySystemComp);
};
