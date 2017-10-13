// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank){ UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank")); }
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}


ATank* ATankPlayerController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // out param
	if (bGetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
		// linetrace through crosshair
		// if it hits something
			//turn turret & barrel towards aimpoint
	}
}

bool ATankPlayerController::bGetSightRayHitLocation(FVector& OutHitLocation) const
{
	// find or set the crosshair position
	int32 OutViewportSizeX, OutViewportSizeY;
	GetViewportSize(OutViewportSizeX, OutViewportSizeY);
	auto ScreenLocation = FVector2D(OutViewportSizeX * AimX, OutViewportSizeX * AimY);
	
	// de-project the screen position of the crosshair to a world direction
	// line-trace along that look direction, and see what we hit (to max range)
	return true;
}