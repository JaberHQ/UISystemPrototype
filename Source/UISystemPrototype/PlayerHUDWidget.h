// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "PlayerMenuWidget.h"
#include "PlayerHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEMPROTOTYPE_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
private:
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

	UPROPERTY()
	TSubclassOf<UUserWidget> PlayerMenuWidgetClass;


	UPROPERTY()
	class UUserWidget* PlayerMenuWidget;

public:
	void DisplayPlayerMenu();


	UPlayerHUDWidget(const FObjectInitializer& ObjectInitializer);

};
