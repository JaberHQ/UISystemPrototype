// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void UPlayerMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	
	AActor* player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UInventorySystemComponent* inventorySystemComp = player->FindComponentByClass<UInventorySystemComponent>();

	InventoryGridWidget->DisplayInventory(inventorySystemComp);
}
