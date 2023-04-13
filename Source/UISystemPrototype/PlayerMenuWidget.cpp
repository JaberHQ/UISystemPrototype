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

	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}


