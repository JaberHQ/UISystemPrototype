// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"

UPlayerHUDWidget::UPlayerHUDWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	/* Find BP 'W_PlayerMenu' widget */
	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerMenuClassFinder(TEXT("/Game/InventorySystem/Widgets/W_PlayerMenu"));
	if(PlayerMenuClassFinder.Class)
	{
		PlayerMenuWidgetClass = PlayerMenuClassFinder.Class;
	}

	/* Find BP 'W_ContainerInventory' widget */
	static ConstructorHelpers::FClassFinder<UContainerInventoryWidget>ContainerInventoryWidgetClassFinder(TEXT("/Game/InventorySystem/Widgets/W_ContainerInventory"));
	if(ContainerInventoryWidgetClassFinder.Class)
	{
		ContainerInventoryWidgetClass = ContainerInventoryWidgetClassFinder.Class;
	}
}

void UPlayerHUDWidget::DisplayPlayerMenu()
{
	/* Create player menu widget */
	if(PlayerMenuWidgetClass)
	{
		PlayerMenuWidget = CreateWidget<UUserWidget>(this, PlayerMenuWidgetClass);
		PlayerMenuWidget->AddToViewport();
	}
}

void UPlayerHUDWidget::ShowContainer(UInventorySystemComponent* containerInventorySystemComponent)
{
	if(ContainerInventoryWidgetClass)
	{
		ContainerInventoryWidget = CreateWidget<UContainerInventoryWidget>(this, ContainerInventoryWidgetClass);
		ContainerInventoryWidget->ContainerInventorySystemComponent = containerInventorySystemComponent;

		//PlayerMenuWidget = ContainerInventoryWidget;
		//PlayerMenuWidget->AddToViewport();
	}
}



