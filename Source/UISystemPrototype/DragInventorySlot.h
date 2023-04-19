// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "InventorySystemComponent.h"
#include "DragInventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEMPROTOTYPE_API UDragInventorySlot : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UInventorySystemComponent* InventorySystemComp; // Reference to inventory system

	int ContentIndex; // Index of slot


};
