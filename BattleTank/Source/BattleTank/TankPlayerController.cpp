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

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
		// linetrace through crosshair
		// if it hits something
			//turn turret & barrel towards aimpoint
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// find or set the crosshair position
	int32 OutViewportSizeX, OutViewportSizeY;
	GetViewportSize(OutViewportSizeX, OutViewportSizeY);
	auto ScreenLocation = FVector2D(OutViewportSizeX * AimX, OutViewportSizeY * AimY);

	/// de-project the screen position of the crosshair to a world direction
	FVector OutLookDirection;

	if (GetLookDirection(ScreenLocation, OutLookDirection))
	{
		// line-trace along that look direction, and see what we hit (to max range)
		GetLookVectorHitLocation(OutLookDirection, OutHitLocation);
	}


	
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector OutLookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (OutLookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false; // raycast did not succeed
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
	FVector CameraWorldLocation; // Unused Vector -> Discard
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		OutLookDirection
	);
	
}


