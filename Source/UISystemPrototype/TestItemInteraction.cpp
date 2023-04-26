// Fill out your copyright notice in the Description page of Project Settings.


#include "TestItemInteraction.h"
#include "Engine/DataTable.h"
#include "InventorySystemComponent.h"

// Sets default values
ATestItemInteraction::ATestItemInteraction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ItemDataComponent = CreateDefaultSubobject<UItemDataComponent>(TEXT("ItemData"));
	
}

// Called when the game starts or when spawned
void ATestItemInteraction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestItemInteraction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FText ATestItemInteraction::LookAt()
{
	/* Display 'pickup' text when item can be picked up */
	FItemStruct* item = ItemDataComponent->ItemID.GetRow<FItemStruct>("Apple");
	if(item)
	{
		FText name = item->Name;
		FText lookAtText = FText::Format(FText::FromString("Pickup {item}"), name);
		return lookAtText;
	}
	return FText();
}

void ATestItemInteraction::InteractWith(AUISystemPrototypeCharacter* playerCharacter)
{
}

