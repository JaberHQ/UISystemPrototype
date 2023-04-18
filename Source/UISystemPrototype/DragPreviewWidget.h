// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "InventorySystemComponent.h"
#include "DragPreviewWidget.generated.h"

/**
 * 
 */
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

	UPROPERTY(EditAnywhere, Category = "DataTable")
	UDataTable* ItemDataTable;

	FName ItemID;

public:
	/* Native Construct */
	virtual void NativeConstruct() override;

	UDragPreviewWidget(const FObjectInitializer& ObjectInitializer);

};
