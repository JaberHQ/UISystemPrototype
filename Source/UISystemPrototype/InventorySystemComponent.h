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
	int32 Quantity;
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
	int32 StackSize;
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

public:

	/* Accessible within editor */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 InventorySize; /* Size of Inventory */

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
	void InteractionTracing();
public:

	void AddToInventory();
	
	void RemoveFromInventory();

	void SetInventorySize(int32 newInventorySize);
	
	int32 GetInventorySize();

	void SetInteractionRange(float interactionRange);
	
	float GetInteractionRange();

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void Interact();

	void InteractWithActor(AActor* target);
	
};
