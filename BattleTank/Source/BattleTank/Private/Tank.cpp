// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank() { PrimaryActorTick.bCanEverTick = false; }
// Called when the game starts or when spawned
void ATank::BeginPlay() { Super::BeginPlay(); }
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{ Super::SetupPlayerInputComponent(PlayerInputComponent); }
