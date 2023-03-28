// Fill out your copyright notice in the Description page of Project Settings.


#include "TestItemInteraction.h"
#include "Engine/DataTable.h"
#include "InventorySystemComponent.h"

// Sets default values
ATestItemInteraction::ATestItemInteraction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	FItemStruct* item = ItemDataComponent->ItemID.GetRow<FItemStruct>("Apple");
	
	FText name = item->Name;
	FText lookAtText = FText::Format(FText::FromString("Pickup"), name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, lookAtText.ToString());
	return lookAtText;


	//FString("Pick up" TEXT(""item->Name.ToString());

	
}

void ATestItemInteraction::InteractWith()
{
}

