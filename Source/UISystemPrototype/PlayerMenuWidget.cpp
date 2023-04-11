// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
void UPlayerMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();


	//AActor* player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	UInventorySystemComponent* inventorySystemComp = player->FindComponentByClass<UInventorySystemComponent>();
	//player->FindComponentByClass<UInventorySystemComponent>();
	//UInventorySystemComponent* inventorySystemComp = player->FindComponentByClass<UInventorySystemComponent>();
	if(inventorySystemComp)
	{
		InventoryGridWidget->DisplayInventory(inventorySystemComp);
	}
}
