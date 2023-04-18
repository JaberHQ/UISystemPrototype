// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryGridWidget.h"

UInventoryGridWidget::UInventoryGridWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	/* Find BP 'W_InventorySlotWidget' */
	static ConstructorHelpers::FClassFinder<UInventorySlotWidget> InventorySlotWidgetClassFinder(TEXT("/Game/InventorySystem/Widgets/W_InventorySlotWidget"));
	if (InventorySlotWidgetClassFinder.Class)
	{
		InventorySlotWidgetClass = InventorySlotWidgetClassFinder.Class;
	}
}

void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(InventorySystemComp)
		DisplayInventory(InventorySystemComp);
}

void UInventoryGridWidget::DisplayInventory(UInventorySystemComponent* inventorySystemComp)
{
	InventorySystemComp = inventorySystemComp;
	GridBox->ClearChildren();
	
	/* Setup item slots */
	if(InventorySystemComp)
	{
		for(int i = 0; i < InventorySystemComp->Content.Num(); i++)
		{
			InventorySlotWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
			InventorySlotWidget->ItemID = InventorySystemComp->Content[i].ItemID;
			InventorySlotWidget->Quantity = InventorySystemComp->Content[i].Quantity;
			InventorySlotWidget->InventorySystemComp = InventorySystemComp;
			InventorySlotWidget->ContentIndex = i;
			GridBox->AddChildToWrapBox(InventorySlotWidget);
		}
	}
}


