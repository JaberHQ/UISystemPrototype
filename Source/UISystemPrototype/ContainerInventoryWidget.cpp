// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerInventoryWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


void UContainerInventoryWidget::NativeConstruct()
{
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UInventorySystemComponent* inventorySystemComponent = player->FindComponentByClass<UInventorySystemComponent>();

	if(inventorySystemComponent)
	{
		PlayerInventory->DisplayInventory(inventorySystemComponent);
	}

	if(ContainerInventorySystemComponent)
	{
		ContainerInventory->DisplayInventory(ContainerInventorySystemComponent);
	}

	

}
