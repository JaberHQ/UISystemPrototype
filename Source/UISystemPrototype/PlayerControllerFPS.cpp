// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerFPS.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APlayerControllerFPS::APlayerControllerFPS()
{
	// Find BP 'W_PlayerHUD'
	static ConstructorHelpers::FClassFinder<UPlayerHUDWidget> PlayerHUDClassFinder(TEXT("/Game/PlayerHUD/W_PlayerHUD"));
	if(PlayerHUDClassFinder.Class)
	{
		PlayerHudWidgetClass = PlayerHUDClassFinder.Class;
	}
}

void APlayerControllerFPS::BeginPlay()
{
	Super::BeginPlay();

	// Get Enhanced player input 
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// Add new mapping context for interacting with items and adding them into the inventory system
		Subsystem->AddMappingContext(InventoryMappingContext, 3);
	}
	if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Input action for interaction (inventory system)
		EnhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Triggered, this, &APlayerControllerFPS::InventoryActionPressed);
	}

	/* Add PlayerHUD Widget to viewport */
	if(PlayerHudWidgetClass)
	{
		PlayerHUDWidget = CreateWidget<UPlayerHUDWidget>(this, PlayerHudWidgetClass);
		PlayerHUDWidget->AddToViewport();
	}
}

void APlayerControllerFPS::InventoryActionPressed()
{
	if(PlayerHUDWidget)
	{
		PlayerHUDWidget->DisplayPlayerMenu();
	}
}