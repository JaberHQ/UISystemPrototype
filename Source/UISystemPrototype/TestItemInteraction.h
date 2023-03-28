// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveInterface.h"
#include "TestItemInteraction.generated.h"

UCLASS()
class UISYSTEMPROTOTYPE_API ATestItemInteraction : public AActor, public IInteractiveInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestItemInteraction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Interface functions */
	virtual FText LookAt() override;

	virtual void InteractWith() override;
};
