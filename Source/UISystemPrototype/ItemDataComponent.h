// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "InteractiveInterface.h"
#include "ItemDataComponent.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: UItemDataComponent
 *
 * Author: Jaber A
 *
 * Purpose: Component that handles all item data
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 28/03/2023    JA          V1.0        Created Item Data Component
*****************************************************************************/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UISYSTEMPROTOTYPE_API UItemDataComponent : public UActorComponent, public IInteractiveInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemDataComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	FDataTableRowHandle ItemID; // Item's unique ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	int Quantity; // Item's quantity

public:
	
	/* Get Item ID from DataTable */
	FDataTableRowHandle GetItemID();

	/* Set Item's Quantity */
	void SetQuantity(int quantity);

	/* Get Item's Quantity */
	int GetQuantity();

/* ***************************** Interface functions ***********************************/
//	
	/* Events for when item is looked at by player */
	virtual FText LookAt() override;

	/* Takes in player reference and executes interaction events */
	virtual void InteractWith(AUISystemPrototypeCharacter* playerCharacter) override;
//
/***************************************************************************************/
};
