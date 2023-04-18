// Fill out your copyright notice in the Description page of Project Settings.


#include "DragPreviewWidget.h"

void UDragPreviewWidget::NativeConstruct()
{
	Super::NativeConstruct();

	FItemStruct* item = ItemDataTable->FindRow<FItemStruct>(ItemID, ItemID.ToString());
	if(item)
	{
		Image->SetBrushFromTexture(item->Thumbnail);
	}
}

UDragPreviewWidget::UDragPreviewWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}
