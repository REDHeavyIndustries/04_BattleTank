// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "Public/UObject/Class.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Public/Tank.h"
#include "Public/Math/Vector2D.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	ATank* GetControlledTank() const;
	
	//Aims Barrel towards aimpoint
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ScreenAimingPosition)
		float AimX = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ScreenAimingPosition)
		float AimY = 0.33333f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaximumFiringRange)
		float LineTraceRange = 1000000.f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
	
	
};
