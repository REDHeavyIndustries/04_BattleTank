// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BattleTank.h"
#include "Public/UObject/Class.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Public/Tank.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	
	
	
	
};