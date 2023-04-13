// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridWidget.h"

void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//DisplayInventory(InventorySystemComp);
	if(InventorySystemComp)
	{
		for(int i =0; i< InventorySystemComp->Content.Num();i++)
		{
			InventorySlotWidget->ItemID = InventorySystemComp->Content[i].ItemID;
			InventorySlotWidget->Quantity = InventorySystemComp->Content[i].Quantity;
			InventorySlotWidget->InventorySystemComp = InventorySystemComp;
			InventorySlotWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
			GridBox->AddChildToWrapBox(InventorySlotWidget);
			//InventorySlotWidget->AddToViewport();
		}
	}
}

void UInventoryGridWidget::DisplayInventory(UInventorySystemComponent* inventorySystemComp)
{
	
	InventorySystemComp = inventorySystemComp;
	GridBox->ClearChildren();
	
	if(InventorySystemComp)
	{
		for(int i = 0; i < InventorySystemComp->Content.Num(); i++)
		{
			InventorySlotWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
			InventorySlotWidget->ItemID = InventorySystemComp->Content[i].ItemID;
			InventorySlotWidget->Quantity = InventorySystemComp->Content[i].Quantity;
			InventorySlotWidget->InventorySystemComp = InventorySystemComp;
			GridBox->AddChildToWrapBox(InventorySlotWidget);
			//InventorySlotWidget->AddToViewport();
		}
	}

}

UInventoryGridWidget::UInventoryGridWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UInventorySlotWidget> InventorySlotWidgetClassFinder(TEXT("/Game/InventorySystem/Widgets/W_InventorySlotWidget"));
	if(InventorySlotWidgetClassFinder.Class)
	{
		InventorySlotWidgetClass = InventorySlotWidgetClassFinder.Class;
	}

	///Script/UMGEditor.WidgetBlueprint'/Game/InventorySystem/Widgets/W_InventorySlotWidget.W_InventorySlotWidget'
}
