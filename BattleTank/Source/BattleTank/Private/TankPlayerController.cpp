// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetControllerTank();
	if (ControlledTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank is: %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No controlled tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticking"));
}

ATank* ATankPlayerController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}