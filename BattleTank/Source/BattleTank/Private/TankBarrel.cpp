// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreeperSecond)
{
	//move the barrel the right amount this frame
	//give the max elevation speed and frame time
	DegreeperSecond = FMath::Clamp<float>(DegreeperSecond, -1, +1);
	auto ElevationChange = DegreeperSecond * MaxElevationDegree * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

