// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
void UPlayerMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();


	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UInventorySystemComponent* inventorySystemComp = player->FindComponentByClass<UInventorySystemComponent>();
	
	if(inventorySystemComp)
	{
		InventoryGridWidget->DisplayInventory(inventorySystemComp);
	}
}

UPlayerMenuWidget::UPlayerMenuWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UInventoryGridWidget> InventoryGridWidgetClassFinder(TEXT("/Game/InventorySystem/Widgets/W_InventoryGrid"));
	if (InventoryGridWidgetClassFinder.Class)
	{
		InventoryGridWidgetClass = InventoryGridWidgetClassFinder.Class;
	}
}
