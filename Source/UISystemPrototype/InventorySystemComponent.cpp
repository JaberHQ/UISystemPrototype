// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "InteractiveInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "ItemDataComponent.h"

// Sets default values for this component's properties
UInventorySystemComponent::UInventorySystemComponent()
	:InventorySize(16)
	,lookAtActor(nullptr)
	,InteractionRange(300.0f)
	,m_localHasFailed(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	/*static ConstructorHelpers::FClassFinder<UDataTable> ItemDataTableClassFinder(TEXT("/Game/InventorySystem/DataTable/ItemData"));
	ItemDataTableClass = ItemDataTableClassFinder.Class;
	if(ItemDataTableClass)
		ItemDataTable = Cast<UDataTable>(ItemDataTableClass);*/


	// Initialise Array
	Content.Init({}, InventorySize);
}


// Called when the game starts
void UInventorySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get player controller
	if(APlayerController* PlayerController = Cast<APlayerController>(GetOwner()->GetInstigatorController()))
	{
		// Get Enhanced players input 
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Add new mapping context for interacting with items and adding them into the inventory system
			Subsystem->AddMappingContext(InteractMappingContext, 2);
		}
		if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			// Input action for interaction (inventory system)
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &UInventorySystemComponent::Interact);
		}
	}

	// Set inventory size
	Content.SetNum(InventorySize);
}


// Called every frame
void UInventorySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	InteractionTracing();
}

void UInventorySystemComponent::InteractionTracing()
{
	// Get POV of player
	APlayerCameraManager* playerCamera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);

	if(playerCamera)
	{
		// Sphere trace from players point of view
		FVector start = playerCamera->GetCameraLocation();
		FVector end = (playerCamera->GetActorForwardVector() * InteractionRange) + start;
		TArray<AActor*> actorsToIgnore;
		actorsToIgnore.Add(GetOwner());
		FHitResult hit;

		// ECC_GameTraceChannel2 is a custom channel created in the editor for collision
		bool bHit = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), start, end, 15.0f, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2),
			false, actorsToIgnore, EDrawDebugTrace::None, hit, true);

		/* If hit set target actor */
		if(bHit)
		{
			if(lookAtActor != hit.GetActor())
			{
				lookAtActor = hit.GetActor();

				// Call interface function for the pickup message
				IInteractiveInterface* interactiveInterface = Cast<IInteractiveInterface>(lookAtActor);
				if(interactiveInterface)
				{
					interactiveInterface->LookAt();
				}
			}
		}
		else
		{
			// Set target actor as null
			lookAtActor = nullptr;
		}
	}
}
void UInventorySystemComponent::AddToInventory(FName itemID, int quantity)
{
	// Set local quantity
	m_quantityRemaining = quantity;
	while(m_quantityRemaining > 0 && !m_localHasFailed)
	{
		// Find a slot
		int index = FindSlot(itemID);

		// If slot available
		if(m_foundSlot)
		{
			// Add to stack
			AddToStack(index, 1); // Adds a single item
			m_quantityRemaining--;
		}

		else
		{
			// Are there any empty slots availalbe
			if(AnyEmptySlotsAvailable())
			{
				// If a new stack can be created
				if(CreateNewStack(itemID, 1))
				{
					m_quantityRemaining--;
				}
				else
				{
					// Exit while loop
					m_localHasFailed = true;
				}
			}
			else
			{
				// Exit while loop
				m_localHasFailed = true;
			}
		}
	}
}

void UInventorySystemComponent::RemoveFromInventory(int index, bool removeWholeStack, bool isConsumed)
{
	TArray<FSlotStruct> tempContent = Content;
	FName tempItemID = tempContent[index].ItemID;
	int	tempItemQuantity = tempContent[index].Quantity;

	if(removeWholeStack || tempItemQuantity == 1)
	{
		Content[index].ItemID = NAME_None;
		if(isConsumed)
		{
		}
		else
		{
			DropItem(tempItemID, tempItemQuantity);
		}
	}
	else
	{
		
		Content[index].Quantity -= 1;

		if(isConsumed)
		{
		}
		else
		{
			DropItem(tempItemID, 1);
		}
	}

	MulticastUpdate();
}

void UInventorySystemComponent::SetInventorySize(int newInventorySize)
{
	InventorySize = newInventorySize;
}

int UInventorySystemComponent::GetInventorySize()
{
	return InventorySize;
}

void UInventorySystemComponent::SetInteractionRange(float interactionRange)
{
	InteractionRange = interactionRange;
}

float UInventorySystemComponent::GetInteractionRange()
{
	return InteractionRange;
}

void UInventorySystemComponent::Interact()
{
	if(lookAtActor)
	{
		InteractWithActor(lookAtActor);
	}
}

void UInventorySystemComponent::InteractWithActor(AActor* target)
{
	// Get player
	AUISystemPrototypeCharacter* playerCharacter = Cast<AUISystemPrototypeCharacter>(GetOwner());

	if(playerCharacter)
	{
		// Get target actors data component
		UItemDataComponent* ItemDataComponent = target->FindComponentByClass<UItemDataComponent>();

		if(ItemDataComponent)
		{
			// If the target has interface applied
			IInteractiveInterface* interactiveInterface = Cast<IInteractiveInterface>(ItemDataComponent);

			if(interactiveInterface)
			{
				// Interact with target actor and player
				if(interactiveInterface && ItemDataComponent)
					interactiveInterface->InteractWith(playerCharacter);
			}
		}

		else
		{
			APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			if(playerController)
			{
				target->SetOwner(playerController);
				OnInteract(target, playerCharacter);
			}
		}
	}
}

void UInventorySystemComponent::OnInteract(AActor* target, AActor* interactor)
{
	AUISystemPrototypeCharacter* playerCharacter = Cast<AUISystemPrototypeCharacter>(interactor);
	if(playerCharacter)
	{
		// If the target has interface applied
		IInteractiveInterface* interactiveInterface = Cast<IInteractiveInterface>(target);
		if(interactiveInterface)
		{
			interactiveInterface->InteractWith(playerCharacter);
		}
	}
}

void UInventorySystemComponent::RemoveItem(int index, bool removeWholeStack, bool isConsumed)
{
}

void UInventorySystemComponent::DropItem(FName itemID, int quantity)
{
	//quantity -= 1;
	for(int i = 0; i< quantity; i++)
	{
		ItemClass = GetItemData(itemID).ItemClass;
		
		FActorSpawnParameters spawnParams;

		FTransform spawnTransform;
		spawnTransform.SetLocation(GetDropLocation());
		//spawnTransform.TransformVector(GetDropLocation());
		//spawnParams.class
		// Spawn actor
		GetWorld()->SpawnActor<AActor>(ItemClass, spawnTransform);
	}
}

FItemStruct& UInventorySystemComponent::GetItemData(FName itemID)
{
	FItemStruct* item = ItemDataTable->FindRow<FItemStruct>(itemID, itemID.ToString());

	return *item;
}

FVector UInventorySystemComponent::GetDropLocation()
{
	int DropRadius = 150.0f;

	FVector randomUnitVector = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(GetOwner()->GetActorForwardVector(), 30.0f);
	FVector start = GetOwner()->GetActorLocation() + (randomUnitVector * DropRadius);
	FVector end = start - FVector(0.0f, 0.0f, 500.0f);
	FHitResult hit;
	FCollisionQueryParams queryParams;
	queryParams.bTraceComplex = false;
	queryParams.AddIgnoredActor(GetOwner());
	bool bHit = GetWorld()->LineTraceSingleByChannel(hit, start, end, ECollisionChannel::ECC_Visibility, queryParams);
	return hit.Location;
}

int UInventorySystemComponent::FindSlot(FName itemID)
{
	// Loop through inventory
	for(int i = 0; i < Content.Num(); i++)
	{
		// If a correct item id is found
		if(Content[i].ItemID == itemID)
		{
			// If the max stack size has not been surpassed
			if(Content[i].Quantity < GetMaxStackSize(itemID))
			{
				// Slot available is true  
				m_foundSlot = true;

				// Return array index of the slot that is avaiable 
				return i;
			}
		}
	}
	// Slot unavailable, return error index
	m_foundSlot = false;
	return -1;
}

int UInventorySystemComponent::GetMaxStackSize(FName itemID)
{
	// Get item data 
	UItemDataComponent* ItemDataComponent = lookAtActor->FindComponentByClass<UItemDataComponent>();
	if(ItemDataComponent)
	{
		// Loop through data table
		FItemStruct* item = ItemDataComponent->ItemID.GetRow<FItemStruct>(itemID.ToString());
		if(item)
		{
			// Return the stacksize of the item
			return item->StackSize;
		}
	}
	else
	{
		FItemStruct* item = ItemDataTable->FindRow<FItemStruct>(itemID, itemID.ToString());
		if(item)
			return item->StackSize;
	}
	return -1;
}

void UInventorySystemComponent::AddToStack(int index, int quantity)
{
	// Copy of Content array
	TArray<FSlotStruct> TempArray;
	TempArray = Content;

	// Find the new quantity
	TempArray[index].Quantity += quantity;
	TempArray[index].ItemID;

	// Set Content array to new quantity
	Content[index].ItemID = TempArray[index].ItemID;
	Content[index].Quantity = TempArray[index].Quantity;
}

bool UInventorySystemComponent::AnyEmptySlotsAvailable()
{
	// Loop through array and find any empty slots
	for(int i =0; i<Content.Num(); i++)
	{
		// If empty slot is available
		if(Content[i].Quantity == 0)
		{
			m_emptyIndex = i;
			return true;
		}
	}
	// No empty slots available
	m_emptyIndex = -1;
	return false;
}

bool UInventorySystemComponent::CreateNewStack(FName itemID, int quantity)
{
	// If there is an empty slot
	if(AnyEmptySlotsAvailable())
	{
		// Set items into empty slot 
		Content[m_emptyIndex].ItemID = itemID;
		Content[m_emptyIndex].Quantity = quantity;
		return true;
	}
	// No empty slot available
	return false;
}

bool UInventorySystemComponent::InventorySlotAvailable()
{
	return !m_localHasFailed;
}

void UInventorySystemComponent::Debug_Print()
{
	/* Debug print inventory */
	for(int i = 0; i<Content.Num(); i++)
	{
		FString debugText;

		debugText.Append(FString::FromInt(i));
		debugText.AppendChar(':');
		debugText.Append(Content[i].ItemID.ToString());
		debugText.Append(" = ");
		debugText.Append(FString::FromInt(Content[i].Quantity));

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, debugText);
	}
}

void UInventorySystemComponent::TransferSlots(int sourceIndex, UInventorySystemComponent* sourceInventory, int destinationIndex)
{
	// Create temporary array to avoid data loss
	TArray<FSlotStruct> tempSourceContent = sourceInventory->Content;

	// Set local slot content to specific slot
	FSlotStruct slotContent = tempSourceContent[sourceIndex];

	/* If index is blank, add inventory item */
	if(destinationIndex < 0)
	{

	}
	else
	{
		TArray<FSlotStruct> tempContent = Content;
		
		// Stack
		if(slotContent.ItemID == tempContent[destinationIndex].ItemID)
		{
			FSlotStruct tempSlot;
			int stack = slotContent.Quantity + tempContent[destinationIndex].Quantity;
			int maxStackSize = GetMaxStackSize(slotContent.ItemID);
			int stackSize = stack - maxStackSize;
			int clampStackSize = UKismetMathLibrary::ClampInt64(stackSize, 0, maxStackSize);

			if(clampStackSize > 0)
			{
				tempSlot.ItemID = slotContent.ItemID;
			}
			else
			{
			}
			
			sourceInventory->Content[sourceIndex].ItemID = tempSlot.ItemID;
			sourceInventory->Content[sourceIndex].Quantity = clampStackSize;

			Content[destinationIndex].ItemID = slotContent.ItemID;

			int clampQuantity = UKismetMathLibrary::ClampInt64(stack, 0, maxStackSize);
			Content[destinationIndex].Quantity = clampQuantity;
			MulticastUpdate();
			sourceInventory->MulticastUpdate();
		}
		else
		{
			/* Transfer slot */
			sourceInventory->Content[sourceIndex] = tempContent[destinationIndex];
			Content[destinationIndex] = slotContent;

			/* Update grid */
			MulticastUpdate();
			sourceInventory->MulticastUpdate();
		}
	}
	

}

void UInventorySystemComponent::MulticastUpdate() 
{
	OnInventoryUpdated.Broadcast();
}





