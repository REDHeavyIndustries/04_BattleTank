// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeRotationSpeed)
{
	RelativeRotationSpeed = FMath::Clamp<float>(RelativeRotationSpeed, -1, +1);
	auto AzimuthChange = RelativeRotationSpeed * MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto TurretAzimuth = RelativeRotation.Yaw + AzimuthChange;
	
	SetRelativeRotation(FRotator(0, TurretAzimuth, 0));
}


