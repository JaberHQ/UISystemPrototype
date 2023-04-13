// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveInterface.h"
#include "ItemDataComponent.h"
#include "TestItemInteraction.generated.h"

/*****************************************************************************
 * Type: Class
 *
 * Name: ATestItemInteraction
 *
 * Author: Jaber A
 *
 * Purpose: Test item to test inventory system pickup
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 31/03/2023    JA          V1.0        Created Test item class
*****************************************************************************/

UCLASS()
class UISYSTEMPROTOTYPE_API ATestItemInteraction : public AActor, public IInteractiveInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestItemInteraction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

/******************************* Interface functions ***********************************/
//	
	/* Events for when item is looked at by player */
	virtual FText LookAt() override;

	/* Takes in player reference and executes interaction events */
	virtual void InteractWith(AUISystemPrototypeCharacter* playerCharacter) override;
//
/**************************************************************************************/

public:
	/** Item Data Component */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	class UItemDataComponent* ItemDataComponent;
};
