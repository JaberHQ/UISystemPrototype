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
void UInventorySystemComponent::AddToInventory()
{
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
	UItemDataComponent* ItemDataComponenent = target->FindComponentByClass<UItemDataComponent>();
	if(ItemDataComponenent)
	{
		IInteractiveInterface* interactiveInterface = Cast<IInteractiveInterface>(ItemDataComponenent);
		if (interactiveInterface)
		{
			interactiveInterface->InteractWith();
		}
	}
}



