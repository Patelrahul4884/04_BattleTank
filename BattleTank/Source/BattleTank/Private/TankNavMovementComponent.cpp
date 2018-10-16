// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "TankNavMovementComponent.h"

void UTankNavMovementComponent::Initialise(UTankTrack*LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	
}
void UTankNavMovementComponent::IntendToMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}



