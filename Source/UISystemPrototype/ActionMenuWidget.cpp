// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionMenuWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void UActionMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	VerticalBox->SetVisibility(ESlateVisibility::Visible);

	FVector2D mousePositionOnViewport = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	UCanvasPanelSlot* canvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(VerticalBox);
	canvasSlot->SetPosition(mousePositionOnViewport);

	UseButton->OnClicked.AddDynamic(this, &UActionMenuWidget::OnUseButtonClicked);
	DropButton->OnClicked.AddDynamic(this, &UActionMenuWidget::OnDropButtonClicked);
	DropAllButton->OnClicked.AddDynamic(this, &UActionMenuWidget::OnDropAllButtonClicked);

}

void UActionMenuWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	RemoveFromParent();
}

void UActionMenuWidget::OnUseButtonClicked()
{
	InventorySystemComponent->RemoveFromInventory(Index, false, true);
}

void UActionMenuWidget::OnDropButtonClicked()
{
	InventorySystemComponent->RemoveFromInventory(Index, false, false);
}

void UActionMenuWidget::OnDropAllButtonClicked()
{
	InventorySystemComponent->RemoveFromInventory(Index, true, false);
}
