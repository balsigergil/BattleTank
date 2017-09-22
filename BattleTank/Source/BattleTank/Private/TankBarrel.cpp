// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	/// Move the barrel the right amount this frame
	/// Given a max elevation speed, and the frame time.
	float time = GetWorld()->GetAudioTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("[%f] Barrel Elevate speed: %f"), time, RelativeSpeed);
}