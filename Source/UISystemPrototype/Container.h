// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventorySystemComponent.h"
#include "InteractiveInterface.h"
#include "ContainerInventoryWidget.h"
#include "Container.generated.h"

UCLASS()
class UISYSTEMPROTOTYPE_API AContainer : public AActor, public IInteractiveInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContainer();

/* Interface functions */
public:
	/* Events for when item is looked at by player */
	virtual FText LookAt() override;

	/* Takes in player reference and executes interaction events */
	virtual void InteractWith(AUISystemPrototypeCharacter* playerCharacter) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	class UInventorySystemComponent* InventorySystemComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
