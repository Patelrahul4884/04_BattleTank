// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreeperSecond)
{
	//move the barrel the right amount this frame
	//give the max elevation speed and frame time
	auto ElevationChange = DegreeperSecond * MaxElevationDegree * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}

