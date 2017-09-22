// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"

// Holds barrel's properties and elevate method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	//TODO Add SetTurretReference

public:
	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
};
