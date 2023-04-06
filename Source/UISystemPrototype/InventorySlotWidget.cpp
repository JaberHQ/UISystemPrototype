// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "Kismet/KismetTextLibrary.h"

void UInventorySlotWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	FItemStruct* item = ItemDataTable->FindRow<FItemStruct>(ItemID, ItemID.ToString());
	if(item)
	{
		Icon->SetBrushFromTexture(item->Thumbnail);
		QuantityText->SetText(UKismetTextLibrary::Conv_IntToText(Quantity));

		QuantitySizeBox->SetVisibility(ESlateVisibility::Visible);
		Icon->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		QuantitySizeBox->SetVisibility(ESlateVisibility::Hidden);
		Icon->SetVisibility(ESlateVisibility::Hidden);
	}
}
void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	
}
