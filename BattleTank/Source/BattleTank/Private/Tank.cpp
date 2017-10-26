// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankMovementComponent.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) { TankAimingComponent->SetTurretReference(TurretToSet); }

// Called when the game starts or when spawned
void ATank::BeginPlay() { Super::BeginPlay(); }

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{ Super::SetupPlayerInputComponent(PlayerInputComponent); }

void ATank::AimAt(FVector OutHitLocation) { TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed); }

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && bIsReloaded) 
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchShell(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}