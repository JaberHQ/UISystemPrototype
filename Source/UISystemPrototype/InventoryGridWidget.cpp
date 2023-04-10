// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridWidget.h"

void UInventoryGridWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	DisplayInventory(InventorySystemComp);
	if(InventorySystemComp)
	{
		for(int i =0; i< InventorySystemComp->Content.Num();i++)
		{
			InventorySlotWidget->ItemID = InventorySystemComp->Content[i].ItemID;
			InventorySlotWidget->Quantity = InventorySystemComp->Content[i].Quantity;
			InventorySlotWidget->InventorySystemComp = InventorySystemComp;
			GridBox->AddChildToWrapBox(InventorySlotWidget);
			//InventorySlotWidget->AddToViewport();
		}
	}
}

void UInventoryGridWidget::DisplayInventory(UInventorySystemComponent* inventorySystemComp)
{
	InventorySystemComp = inventorySystemComp;
	GridBox->ClearChildren();
}
