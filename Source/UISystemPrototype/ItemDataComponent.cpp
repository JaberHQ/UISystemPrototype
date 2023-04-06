// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataComponent.h"
#include "InventorySystemComponent.h"
// Sets default values for this component's properties
UItemDataComponent::UItemDataComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	

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

void UItemDataComponent::SetQuantity(int quanitity)
{
	Quantity = quanitity;
}

int UItemDataComponent::GetQuantity()
{
	return Quantity;
}

FText UItemDataComponent::LookAt()
{
	return FText();
}

void UItemDataComponent::InteractWith(AUISystemPrototypeCharacter* playerCharacter)
{
	if(playerCharacter)
	{
		UInventorySystemComponent* inventorySystem = playerCharacter->FindComponentByClass<UInventorySystemComponent>();
		if(inventorySystem)
		{
			inventorySystem->AddToInventory(ItemID.RowName, Quantity);
			if(inventorySystem->InventorySlotAvailable())
			{
				GetOwner()->Destroy();
			}
		}
	}
}

