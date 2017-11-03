// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/UObject/Class.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Public/Math/Vector2D.h"
#include "TankAIController.generated.h"

//FWD DECS
class UTankAimingComponent;
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	float AcceptanceRadius = 3000;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
