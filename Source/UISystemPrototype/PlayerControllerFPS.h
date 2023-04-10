// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerHUDWidget.h"
#include "PlayerControllerFPS.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEMPROTOTYPE_API APlayerControllerFPS : public APlayerController
{
	GENERATED_BODY()
	
private:
	/* Function when inventory action is pressed */
	void InventoryActionPressed();

protected:
	virtual void BeginPlay() override;


public:
	/** Interact Mapping Context **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InventoryMappingContext;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventoryAction;

	UPROPERTY()
	class UPlayerHUDWidget* PlayerHUDWidget;
};
