// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "InteractiveInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ItemDataComponent.h"
// Sets default values for this component's properties
UInventorySystemComponent::UInventorySystemComponent()
	:InventorySize(16)
	,InteractionRange(300.0f)
	,lookAtActor(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
}


// Called when the game starts
void UInventorySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	if (APlayerController* PlayerController = Cast<APlayerController>(GetOwner()->GetInstigatorController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InteractMappingContext, 2);
		}
		if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &UInventorySystemComponent::Interact);
		}
	}
	Content.SetNum(InventorySize);
}


// Called every frame
void UInventorySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	InteractionTracing();
}

void UInventorySystemComponent::InteractionTracing()
{
	APlayerCameraManager* playerCamera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);

	if (playerCamera)
	{
		FVector start = playerCamera->GetCameraLocation();
		FVector end = (playerCamera->GetActorForwardVector() * InteractionRange) + start;
		TArray<AActor*> actorsToIgnore;
		actorsToIgnore.Add(GetOwner());
		FHitResult hit;
		bool bHit = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), start, end, 15.0f, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2),
			false, actorsToIgnore, EDrawDebugTrace::None, hit, true);

		if(bHit)
		{
			if(lookAtActor != hit.GetActor())
			{
				lookAtActor = hit.GetActor();

				IInteractiveInterface* interactiveInterface = Cast<IInteractiveInterface>(lookAtActor);
				if (interactiveInterface)
				{
					interactiveInterface->LookAt();
				}
			}
			
			
		}
		else
		{
			lookAtActor = nullptr;
		}
	}
}
void UInventorySystemComponent::AddToInventory(FName itemID, int32 quantity)
{
	m_quantityRemaining = quantity;
	while(m_quantityRemaining > 0 && !m_localHasFailed)
	{
		int32 index = FindSlot(itemID);
		if(m_foundSlot)
		{
			AddToStack(index, 1); // Adds a single item
			m_quantityRemaining--;
		}
		else
		{
			if(AnyEmptySlotsAvailable())
			{
				if(CreateNewStack(itemID, 1))
				{
					m_quantityRemaining--;
				}
				else
				{
					m_localHasFailed = true;
				}
			}
			else
			{
				m_localHasFailed = true;
			}
		}
	}
}

void UInventorySystemComponent::RemoveFromInventory()
{
}

void UInventorySystemComponent::SetInventorySize(int32 newInventorySize)
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
	UItemDataComponent* ItemDataComponent = target->FindComponentByClass<UItemDataComponent>();
	if(ItemDataComponent)
	{
		IInteractiveInterface* interactiveInterface = Cast<IInteractiveInterface>(ItemDataComponent);
		if(interactiveInterface)
		{
			//UISystemPrototypeCharacter* playerCharacter = GetWorld()->GetFirstPlayerController()->GetCharacter();
			AUISystemPrototypeCharacter* playerCharacter = Cast<AUISystemPrototypeCharacter>(GetOwner());
			if(playerCharacter)
			{
				interactiveInterface->InteractWith(playerCharacter);
			}
		}
	}
}

int32 UInventorySystemComponent::FindSlot(FName itemID)
{
	for(int i = 0; i< Content.Num(); i++)
	{
		if(Content[i].ItemID == itemID)
		{
			if(Content[i].Quantity < GetMaxStackSize(itemID))
			{
				m_foundSlot = true;
				return i;
			}
		}
	}
	m_foundSlot = false;
	return -1;
}

int32 UInventorySystemComponent::GetMaxStackSize(FName itemID)
{
	UItemDataComponent* ItemDataComponent = lookAtActor->FindComponentByClass<UItemDataComponent>();

	if(ItemDataComponent)
	{
		FItemStruct* item = ItemDataComponent->ItemID.GetRow<FItemStruct>(itemID.ToString());
		if(item)
		{
			return item->StackSize;
		}
	}
	return -1;
}

void UInventorySystemComponent::AddToStack(int32 index, int32 quantity)
{
	TArray<FSlotStruct> TempArray;
	TempArray = Content;
	TempArray[index].Quantity += quantity;
	TempArray[index].ItemID;
	Content[index].ItemID = TempArray[index].ItemID;
	Content[index].Quantity = TempArray[index].Quantity;
	

}

bool UInventorySystemComponent::AnyEmptySlotsAvailable()
{
	for(int i =0; i<Content.Num(); i++)
	{
		if(Content[i].Quantity == 0)
		{
			m_emptyIndex = i;
			return true;
		}
	}
	m_emptyIndex = -1;
	return false;
}

bool UInventorySystemComponent::CreateNewStack(FName itemID, int32 quantity)
{
	if(AnyEmptySlotsAvailable())
	{
		Content[m_emptyIndex].ItemID = itemID;
		Content[m_emptyIndex].Quantity = quantity;
		return true;
	}
	return false;
}

bool UInventorySystemComponent::InventorySlotAvailable()
{
	return !m_localHasFailed;
}

void UInventorySystemComponent::Debug_Print()
{
	for(int i = 1; i<Content.Num(); i++)
	{
		//FString::Appendf(index, ';', Content[i].ItemID, ' = ', Content[i].Quantity);
		FString debugText;

		debugText.Append(FString::FromInt(i));
		debugText.AppendChar(':');
		debugText.Append(Content[i].ItemID.ToString());
		debugText.Append(" = ");
		debugText.Append(FString::FromInt(Content[i].Quantity));

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, debugText);

	}
}



