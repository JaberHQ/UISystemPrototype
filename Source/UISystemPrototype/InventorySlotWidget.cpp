// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "Kismet/KismetTextLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	/* Find BP 'W_PlayerMenu' widget */
	static ConstructorHelpers::FClassFinder<UDragPreviewWidget> DragPreviewWidgetClassFinder(TEXT("/Game/InventorySystem/Widgets/W_DragPreview"));
	if(DragPreviewWidgetClassFinder.Class)
	{
		DragPreviewWidgetClass = DragPreviewWidgetClassFinder.Class;
	}
}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/* If item in slot, set as visible
	   else keep hidden */
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

	bIsFocusable = true;
}

FReply UInventorySlotWidget::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
	if(!ItemID.IsNone())
	{
		if(InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
		{
			return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
		}
	}
	return FReply::Unhandled();

}

void UInventorySlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	DragPreviewWidget = CreateWidget<UDragPreviewWidget>(this, DragPreviewWidgetClass);
	DragPreviewWidget->ItemID = ItemID;
	
	DragInventorySlot = NewObject<UDragInventorySlot>();
	DragInventorySlot->DefaultDragVisual = DragPreviewWidget;
	DragInventorySlot->InventorySystemComp = InventorySystemComp;
	DragInventorySlot->ContentIndex = ContentIndex;

	OutOperation = DragInventorySlot;
}
