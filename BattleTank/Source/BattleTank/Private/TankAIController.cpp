// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{

		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false);
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//ControlledTank->Fire(); //TODO limit firing rate

	}
}






