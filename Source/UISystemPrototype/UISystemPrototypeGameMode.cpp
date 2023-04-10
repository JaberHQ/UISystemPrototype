// Copyright Epic Games, Inc. All Rights Reserved.

#include "UISystemPrototypeGameMode.h"
#include "UISystemPrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUISystemPrototypeGameMode::AUISystemPrototypeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// Set player controller class to PlayerControllerFPS
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_PlayerControllerFPS"));
	PlayerControllerClass = PlayerControllerClassFinder.Class;
}
