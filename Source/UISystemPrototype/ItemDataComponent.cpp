// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataComponent.h"

// Sets default values for this component's properties
UItemDataComponent::UItemDataComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	static ConstructorHelpers::FObjectFinder<UDataTable>
		itemData(TEXT("/Game/InventorySystem/DataTable/ItemData.ItemData"));

	ItemID.DataTable = itemData.Object;

	Quantity = 1;
}


// Called when the game starts
void UItemDataComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UItemDataComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FDataTableRowHandle UItemDataComponent::GetItemID()
{
	return ItemID;
}

void UItemDataComponent::SetQuantity(int32 quanitity)
{
	Quantity = quanitity;
}

int32 UItemDataComponent::GetQuantity()
{
	return Quantity;
}

FText UItemDataComponent::LookAt()
{
	return FText();
}

void UItemDataComponent::InteractWith()
{
	GetOwner()->Destroy();
}

