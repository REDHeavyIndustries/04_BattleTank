// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationSpeed = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDepression = 5;
};
