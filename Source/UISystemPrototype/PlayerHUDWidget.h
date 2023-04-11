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
	TSubclassOf<UPlayerHUDWidget> PlayerMenuWidgetClass;


	UPROPERTY()
	class UUserWidget* PlayerMenuWidget;
public:
	void DisplayPlayerMenu();

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

};
