// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"

void UPlayerHUDWidget::DisplayPlayerMenu()
{
	PlayerMenuWidget = CreateWidget<UPlayerMenuWidget>(this, PlayerMenuWidgetClass);

	if(PlayerMenuWidget)
	{
		PlayerMenuWidget->AddToViewport();
	}
}

void UPlayerHUDWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	static ConstructorHelpers::FClassFinder<UPlayerMenuWidget> PlayerMenuClassFinder(TEXT("/Game/InventorySystem/Widgets/W_PlayerMenu"));
	PlayerMenuWidgetClass = PlayerMenuClassFinder.Class;
}

void UPlayerHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/*static ConstructorHelpers::FClassFinder<UPlayerMenuWidget> PlayerMenuClassFinder(TEXT("/Game/InventorySystem/Widgets/W_PlayerMenu"));
	TSubclassOf<UPlayerHUDWidget> PlayerMenuWidgetClass;
	PlayerMenuWidgetClass = PlayerMenuClassFinder.Class;*/

	//PlayerMenuWidget = CreateWidget<UPlayerHUDWidget>(this, PlayerMenuWidgetClass);

}
