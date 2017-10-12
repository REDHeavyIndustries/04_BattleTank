// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTank.h"
#include "Public/UObject/Class.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Public/Tank.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	//Aims Barrel towards aimpoint
	void AimTowardsCrosshair();
	
	ATank* GetControlledTank() const;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	
	
};
