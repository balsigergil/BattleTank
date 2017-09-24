// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include <iostream>

void UTankBarrel::Elevate(float RelativeSpeed)
{
	/// Move the barrel the right amount this frame
	/// Given a max elevation speed, and the frame time.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	RawNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}
