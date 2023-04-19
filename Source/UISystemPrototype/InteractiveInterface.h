// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UISystemPrototypeCharacter.h"
#include "InteractiveInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractiveInterface : public UInterface
{
	GENERATED_BODY()
};

/*****************************************************************************************************
 * Type: Class
 *
 * Name: IInteractiveInterface
 *
 * Author: Jaber A
 *
 * Purpose: Interface for items that are being interacted with by the player
 * 
 * Change Log:
 * Date          Initials    Version     Comments
 * 28/03/2023    JA          V1.0        Created interface class
*****************************************************************************************************/
class UISYSTEMPROTOTYPE_API IInteractiveInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/* Message for when item is being looked at */
	virtual FText LookAt() = 0;

	/* Events when item is interacted with */
	virtual void InteractWith(AUISystemPrototypeCharacter* playerCharacter) = 0;
};
