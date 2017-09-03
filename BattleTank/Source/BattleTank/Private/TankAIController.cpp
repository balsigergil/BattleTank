// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetControllerTank();
	if (ControlledTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank is: %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No controlled tank"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Player tank is: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}
}

ATank* ATankAIController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
