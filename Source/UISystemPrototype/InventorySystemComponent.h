// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "DisplayMessageWidget.h"
#include "ItemFX.h"
#include "InventorySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInventoryUpdated);
/*****************************************************************************
 * Type: Struct
 *
 * Name: FSlotStruct
 *
 * Author: Jaber A
 *
 * Purpose: Struct for inventory slot data
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 28/03/2023    JA          V1.0        Created slot struct
*****************************************************************************/
USTRUCT(BlueprintType)
struct FSlotStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FName ItemID; // Slot's unique item ID

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int Quantity; // Quantity of item
};

/*****************************************************************************
 * Type: Struct
 *
 * Name: FItemStruct
 *
 * Author: Jaber A
 *
 * Purpose: Struct for item data
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 28/03/2023    JA          V1.0        Created item struct
*****************************************************************************/
USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FText Name; // Name of item

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FText Description; // Description of item

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* Thumbnail; // Image displaying what the item is

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TSubclassOf<class AActor> ItemClass; // Actor class reference

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int StackSize; // The amount you can stack of this item

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TSubclassOf <class AItemFX> ItemEffect;
};


/*****************************************************************************
 * Type: Class
 *
 * Name: UInventorySystemComponent
 *
 * Author: Jaber A
 *
 * Purpose: Handles all inventory system events and data
 *
 * Change Log:
 * Date          Initials    Version     Comments
 * 28/03/2023    JA          V1.0        Created Inventory System class
*****************************************************************************/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UISYSTEMPROTOTYPE_API UInventorySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventorySystemComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/** Multicast delegate function to broadcast inventory update *
	 * See: FOnInventoryUpdate delegate */
	UFUNCTION()
	void MulticastUpdate();

	/* Debug print inventory system */
	UFUNCTION(BlueprintCallable)
	void Debug_Print();

public:
	/* Add item to inventory */
	void AddToInventory(FName itemID, int quantity);

	/* Remove an item from inventory */
	void RemoveFromInventory(int index, bool removeWholeStack, bool isConsumed);

	/* Set new inventory size */
	void SetInventorySize(int newInventorySize);

	/* Returns the current inventory size */
	int GetInventorySize();

	/* Set the interaction range of interactable objects */
	void SetInteractionRange(float interactionRange);

	/* Get the interaction range of interactable objects */
	float GetInteractionRange();

	/* Interact function called from enhanced input key */
	void Interact();

	/* Find inventory slot *
	* Returns an index of an usable slot */
	int FindSlot(FName itemID);

	/* Get the max stack size of an item */
	int GetMaxStackSize(FName itemID);

	/* Add item to a stack */
	void AddToStack(int index, int quantity);

	/* Check if any empty slots are available */
	bool AnyEmptySlotsAvailable();

	/* Creates a new stack in inventory */
	bool CreateNewStack(FName itemID, int quantity);

	/* Checks if inventory slot is available */
	bool InventorySlotAvailable();

	/* Transfer item into new slot */
	void TransferSlots(int sourceIndex, UInventorySystemComponent* sourceInventory, int destinationIndex);

	/* Interaction between object and owner */
	void OnInteract(AActor* target, AActor* interactor);

	/* Drop item onto the ground */
	void DropItem(FName itemID, int quantity);

	/* Get the respective item struct from the itemID */
	FItemStruct& GetItemData(FName itemID);

	/* Find a random drop location within the player radius */
	FVector GetDropLocation();

	void ConsumeItem(int index);

	void SpawnConsumeEffect(FName itemID);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	/* Sphere trace to see if there is an item to interact within radius of the player */
	void InteractionTracing();

	/* Interact with target actor */
	void InteractWithActor(AActor* target);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int InventorySize; // Size of Inventory 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FSlotStruct> Content; // An array for the content of the inventory

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	float InteractionRange; // Range for interaction of objects 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InteractMappingContext; // Interact Mapping Context 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction; // Interact Input Action 

	UPROPERTY(EditAnywhere, Category = "Inventory")
	UDataTable* ItemDataTable; // Item DataTable reference 

public:
	FOnInventoryUpdated OnInventoryUpdated; // Delegate

private:
	AActor* lookAtActor; // Target actor
	int m_quantityRemaining; // Local quantity Remaining
	bool m_localHasFailed; // Fail safe for while loop
	bool m_foundSlot; // Slot has been found
	int m_emptyIndex; // The last empty index of inventory slot
	TSubclassOf<AActor> ItemClass; // Actor of Item Reference
	TSubclassOf<UDisplayMessageWidget> DisplayMessageWidgetClass; // DisplayMessageWidget Class Reference
	UDisplayMessageWidget* DisplayMessage;

};
