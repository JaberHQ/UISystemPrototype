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

	static ConstructorHelpers::FClassFinder<UActionMenuWidget> ActionMenuWidgetClassFinder(TEXT("/Game/InventorySystem/Widgets/W_ActionMenu"));
	if(ActionMenuWidgetClassFinder.Class)
	{
		ActionMenuWidgetClass = ActionMenuWidgetClassFinder.Class;
	}
}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/* If item in slot, set as visible */
	FItemStruct* item = ItemDataTable->FindRow<FItemStruct>(ItemID, ItemID.ToString());
	if(item)
	{
		Icon->SetBrushFromTexture(item->Thumbnail);
		QuantityText->SetText(UKismetTextLibrary::Conv_IntToText(Quantity));

		QuantitySizeBox->SetVisibility(ESlateVisibility::Visible);
		Icon->SetVisibility(ESlateVisibility::Visible);
	}

	/* Else keep hidden */
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

	/* If Item is not empty */
	if(!ItemID.IsNone())
	{
		/* Detect if item is being dragged with left mouse click */
		if(InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
		{
			return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
		}

		/* Detect if item has been right clicked (for drop down menu) */
		if(InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
		{
			if(ActionMenu)
				ActionMenu->RemoveFromParent(); // If there is an action menu already, remove it

			/* Create Action Menu */
			ActionMenu = CreateWidget<UActionMenuWidget>(this, ActionMenuWidgetClass);
			ActionMenu->InventorySystemComponent = InventorySystemComp;
			ActionMenu->Index = ContentIndex;
			ActionMenu->AddToViewport();
			
		}
	}
	return FReply::Unhandled();

}

void UInventorySlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	/* Create drag preview widget */
	DragPreviewWidget = CreateWidget<UDragPreviewWidget>(this, DragPreviewWidgetClass);
	DragPreviewWidget->ItemID = ItemID;
	
	/* Create Drag and Drop operation */
	DragInventorySlot = NewObject<UDragInventorySlot>();
	DragInventorySlot->DefaultDragVisual = DragPreviewWidget;
	DragInventorySlot->InventorySystemComp = InventorySystemComp;
	DragInventorySlot->ContentIndex = ContentIndex;

	OutOperation = DragInventorySlot;
}

bool UInventorySlotWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	/* Transfer inventory slots */
	UDragInventorySlot* dragInventory = Cast<UDragInventorySlot>(InOperation);
	if(dragInventory)
	{
		/* If the content index are different or the inventory systems are not the same */
		if(dragInventory->ContentIndex != ContentIndex 
			|| dragInventory->InventorySystemComp != InventorySystemComp)
		{
			// Transfer slots
			InventorySystemComp->TransferSlots(dragInventory->ContentIndex, dragInventory->InventorySystemComp, ContentIndex);
			return true;
		}
	}
	return false;
}

