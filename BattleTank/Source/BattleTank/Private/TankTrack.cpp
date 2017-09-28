// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottleRotation(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	float RotationApplied = Throttle * TrackMaxDrivingForce * GetWorld()->DeltaTimeSeconds;
	USceneComponent* TankRoot = GetOwner()->GetRootComponent();
	TankRoot->AddLocalRotation(FRotator(0, RotationApplied, 0));
}

void UTankTrack::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * Throttle * 40000000;
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForce(ForceApplied);
}
