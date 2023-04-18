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
	if(InKeyEvent.GetKey() == EKeys::I)
	{
		RemoveFromParent();
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

//FReply UPlayerMenuWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
//{
//	if (InKeyEvent.GetKey() == EKeys::I)
//	{
//		RemoveFromParent();
//		return FReply::Handled();
//	}
//	return FReply::Unhandled();
//}




