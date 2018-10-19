// Fill out your copyright notice in the Description page of Project Settings.


#include "TankNavMovementComponent.h"
#include "TankTrack.h"

void UTankNavMovementComponent::Initialise(UTankTrack*LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
void UTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntension = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntension);
	IntendToMoveForward(ForwardThrow);
	
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntension).Z;
	IntendTurnRight(RightThrow);
}
void UTankNavMovementComponent::IntendToMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}
void UTankNavMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
