// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		WorldSpaceAim,
		LaunchSpeed
	);

	if (bHaveAimSolution) {
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("Aim solution found !"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No aim solution found"));
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	/// Work-out difference between current barrel rotation, and AimDirection.
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5); // TODO Remove magic number
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}
