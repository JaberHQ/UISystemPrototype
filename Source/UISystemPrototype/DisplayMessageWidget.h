// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "DisplayMessageWidget.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEMPROTOTYPE_API UDisplayMessageWidget : public UUserWidget
{
	GENERATED_BODY()
	
/*Overriden UUserWidget functions */
public:
	virtual void NativeConstruct() override;

public:
	void ShowMessage(FText message);

private:

	void SetMessagePrompt();

/* UMG Components */
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel;

	UPROPERTY(meta = (BindWidget))
	class UBorder* Border;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* MessageText;

private:
	FText Message;
};
