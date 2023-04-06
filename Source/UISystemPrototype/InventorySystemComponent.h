// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "InventorySystemComponent.generated.h"

// Struct for slots
USTRUCT(BlueprintType)
struct FSlotStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int Quantity;
};

// Struct for items
USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TSubclassOf<class AActor> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int StackSize;
};


// Inventory System Component Class
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UISYSTEMPROTOTYPE_API UInventorySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventorySystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AActor* lookAtActor;
	int m_quantityRemaining;
	bool m_localHasFailed;
	bool m_foundSlot;
	int m_emptyIndex;
public:

	/* Accessible within editor */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int InventorySize; /* Size of Inventory */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FSlotStruct> Content; /* An array for the content of the inventory */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	float InteractionRange; /* Range for interaction of objects */

	/** Interact Mapping Context **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InteractMappingContext;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

private:
	/* Check if there is an item to interact */
	void InteractionTracing();
public:

	/* Add item to inventory */
	void AddToInventory(FName itemID, int quantity);
	
	/* Remove an item from inventory*/
	void RemoveFromInventory();

	/* Set new inventory size */
	void SetInventorySize(int newInventorySize);
	
	/* Get the current inventory size */
	int GetInventorySize();

	/* Set the interaction range of interactable objects */
	void SetInteractionRange(float interactionRange);
	
	/* Get the interaction range of interactable objects */
	float GetInteractionRange();

	/* Interact function called from enhanced input key */
	UFUNCTION(BlueprintCallable, Category = "Interact")
	void Interact();

	/* Interact with target actor */
	void InteractWithActor(AActor* target);
	
	/* Find inventory slot */
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

	UFUNCTION(BlueprintCallable)
	void Debug_Print();
};
