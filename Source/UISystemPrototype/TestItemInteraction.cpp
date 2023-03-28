// Fill out your copyright notice in the Description page of Project Settings.


#include "TestItemInteraction.h"

// Sets default values
ATestItemInteraction::ATestItemInteraction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Test123"));
	return FText();
}

void ATestItemInteraction::InteractWith()
{
}

