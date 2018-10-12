// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"




void UTankTurret::Azimuth(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto AzimuthChange = RelativeSpeed * MaxDegreeperSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + AzimuthChange;
	SetRelativeRotation(FRotator(0,Rotation,0));
}