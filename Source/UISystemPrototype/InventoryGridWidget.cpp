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

	/* Setup item slots */
	if(InventorySystemComp)
	{
		ConstructInventoryGrid(InventorySystemComp);

		// Bind delegate function
		InventorySystemComp->OnInventoryUpdated.AddUObject(this, &UInventoryGridWidget::UpdatedInventory);
	}
}

void UInventoryGridWidget::ConstructInventoryGrid(UInventorySystemComponent* inventorySystemComp)
{
	// Clear all slots
	GridBox->ClearChildren();

	/* Construct grid consisting of slot widgets */
	for(int i = 0; i < InventorySystemComp->Content.Num(); i++)
	{
		/* Set the correct data for each slot widget */
		InventorySlotWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
		InventorySlotWidget->ItemID = InventorySystemComp->Content[i].ItemID;
		InventorySlotWidget->Quantity = InventorySystemComp->Content[i].Quantity;
		InventorySlotWidget->InventorySystemComp = InventorySystemComp;
		InventorySlotWidget->ContentIndex = i;

		// Add to grid
		GridBox->AddChildToWrapBox(InventorySlotWidget);
	}
}

void UInventoryGridWidget::UpdatedInventory()
{
	if(InventorySystemComp)
	{
		ConstructInventoryGrid(InventorySystemComp);
	}
	
}


