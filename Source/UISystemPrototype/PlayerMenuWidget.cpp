// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
void UPlayerMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/* Get inventory system component from player */
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UInventorySystemComponent* inventorySystemComp = player->FindComponentByClass<UInventorySystemComponent>();
	
	if(inventorySystemComp)
	{
		InventoryGridWidget->DisplayInventory(inventorySystemComp);
	}

	/* Set input mode to UI */
	FInputModeUIOnly inputModeUI;
	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if(playerController)
	{
		playerController->SetInputMode(inputModeUI);
		InventoryGridWidget->bIsFocusable = true;
		InventoryGridWidget->SetFocus();
		playerController->bShowMouseCursor = true;
	}

	bIsFocusable = true;
}

void UPlayerMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();

	/* Set input mode back to 'Game' when widget is destroyed */
	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if(playerController)
	{
		FInputModeGameOnly inputModeGame;
		playerController->SetInputMode(inputModeGame);
		playerController->bShowMouseCursor = false;
	}
}

FReply UPlayerMenuWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyDown(InGeometry, InKeyEvent);

	/* If 'I' key is pressed while player menu is open */
	if(InKeyEvent.GetKey() == EKeys::I)
	{
		// Remove widget from parent
		RemoveFromParent();
		return FReply::Handled();
	}
	return FReply::Unhandled();
}






