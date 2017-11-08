// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Public/Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() { PrimaryComponentTick.bCanEverTick = true; }

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UTankAimingComponent::InitialiseAim(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (bool bIsReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) < ReloadTimeInSeconds)
	{ FiringState = EFiringState::Reloading; }
	else if (bIsBarrelMoving()) { FiringState = EFiringState::Aiming; }
	else { FiringState = EFiringState::Locked; }
}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

bool UTankAimingComponent::bIsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.01);
}

void UTankAimingComponent::AimAt(FVector OutHitLocation)
{
	if (!ensure(Barrel)) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bFireSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bFireSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	auto TurretAzimuth = Turret->GetForwardVector().Rotation();
	auto DeltaAzimuth = AimAsRotator - TurretAzimuth;
	Barrel->Elevate(DeltaRotator.Pitch);
	if (DeltaAzimuth.Yaw > 180.f) { Turret->RotateTurret(-DeltaAzimuth.Yaw); }
	else { Turret->RotateTurret(DeltaAzimuth.Yaw); }
}

void UTankAimingComponent::Fire()
{
	if (FiringState != EFiringState::Reloading)
	{
		if (!ensure(Barrel)) { return; }
		if (!ensure(ProjectileBlueprint)) { return; }
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));
			Projectile->LaunchShell(LaunchSpeed);
			LastFireTime = GetWorld()->GetTimeSeconds();
	}
}


