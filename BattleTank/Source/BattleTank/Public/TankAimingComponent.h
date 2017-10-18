// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

//FWD DECS
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector OutHitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	// TODO Add a 'Set Turret Reference"


private:
	UTankBarrel* Barrel = nullptr;
	void MoveBarrel(FVector AimDirection);
};
