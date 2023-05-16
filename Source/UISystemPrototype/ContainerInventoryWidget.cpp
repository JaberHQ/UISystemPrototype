// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerInventoryWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


void UContainerInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UInventorySystemComponent* inventorySystemComponent = player->FindComponentByClass<UInventorySystemComponent>();

	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	

	if(inventorySystemComponent)
	{
		PlayerInventory->DisplayInventory(inventorySystemComponent);
	}

	if(ContainerInventorySystemComponent)
	{
		ContainerInventory->SetFocus();
		ContainerInventory->DisplayInventory(ContainerInventorySystemComponent);
		
	}

	if(playerController)
	{
		FInputModeUIOnly inputModeUI;
		playerController->SetInputMode(inputModeUI);
		playerController->SetShowMouseCursor(true);
	}
}

void UContainerInventoryWidget::NativeDestruct()
{
	Super::NativeDestruct();



	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if(playerController)
	{
		FInputModeGameOnly inputModeGame;
		playerController->SetInputMode(inputModeGame);
		playerController->SetShowMouseCursor(false);
	}
}

FReply UContainerInventoryWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyDown(InGeometry, InKeyEvent);

	/* If 'I' or 'E' key is pressed while inventory is open */
	if(InKeyEvent.GetKey() == EKeys::E || InKeyEvent.GetKey() == EKeys::I)
	{
		// Remove widget from parent
		RemoveFromParent();
		return FReply::Handled();
	}
	return FReply::Unhandled();
}
