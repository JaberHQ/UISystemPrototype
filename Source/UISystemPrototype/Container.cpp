// Fill out your copyright notice in the Description page of Project Settings.

#include "Container.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerControllerFPS.h"

// Sets default values
AContainer::AContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Mesh = CreateDefaultSubobject<UStaticMesh>(TEXT("Mesh"));

	InventorySystemComponent = CreateDefaultSubobject<UInventorySystemComponent>(TEXT("InventorySystem"));
	InventorySystemComponent->SetInventorySize(32);
	InventorySystemComponent->SetInteractionRange(300.0f);
}

// Called when the game starts or when spawned
void AContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FText AContainer::LookAt()
{
	return FText();
}

void AContainer::InteractWith(AUISystemPrototypeCharacter* playerCharacter)
{
	APlayerControllerFPS* playerController = Cast<APlayerControllerFPS>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(playerController)
	{
		playerController->PlayerHUDWidget->ShowContainer(InventorySystemComponent);
	}
}


