// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DataGathererActor.h"
#include "DataGeneratorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDataGeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDataGeneratorComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Create an event in the data gatherer
	UFUNCTION( BlueprintCallable, Category = "DataTracking" )
	void GenerateEvent(FString EventName, bool Success = true);

	UFUNCTION( BlueprintCallable, Category = "DataTracking" )
	void BeginTracking();

	UFUNCTION( BlueprintCallable, Category = "DataTracking" )
	void StopTracking();

	ADataGathererActor* DataGathererActor;
};
