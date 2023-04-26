// Fill out your copyright notice in the Description page of Project Settings.


#include "DisplayMessageWidget.h"

void UDisplayMessageWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetVisibility(ESlateVisibility::Hidden);
	SetMessagePrompt();


}

void UDisplayMessageWidget::ShowMessage(FText message)
{
	Message = message;
	SetMessagePrompt();
}

void UDisplayMessageWidget::SetMessagePrompt()
{
	MessageText->SetText(Message);

	Message.IsEmpty() ?
		SetVisibility(ESlateVisibility::Hidden) : SetVisibility(ESlateVisibility::HitTestInvisible);
}
