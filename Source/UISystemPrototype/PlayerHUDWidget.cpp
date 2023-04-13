// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"

void UPlayerHUDWidget::DisplayPlayerMenu()
{
	if(PlayerMenuWidgetClass)
	{
		PlayerMenuWidget = CreateWidget<UUserWidget>(this, PlayerMenuWidgetClass);
		PlayerMenuWidget->AddToViewport();
	}
}


UPlayerHUDWidget::UPlayerHUDWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerMenuClassFinder(TEXT("/Game/InventorySystem/Widgets/W_PlayerMenu"));
	if (PlayerMenuClassFinder.Class)
	{
		PlayerMenuWidgetClass = PlayerMenuClassFinder.Class;
	}
}
