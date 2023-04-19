// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"

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
	//CreateWidget<UInventorySystemComponent>()
}


UPlayerHUDWidget::UPlayerHUDWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	/* Find BP 'W_PlayerMenu' widget */
	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerMenuClassFinder(TEXT("/Game/InventorySystem/Widgets/W_PlayerMenu"));
	if (PlayerMenuClassFinder.Class)
	{
		PlayerMenuWidgetClass = PlayerMenuClassFinder.Class;
	}
}
