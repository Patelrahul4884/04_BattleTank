// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankNavMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendToMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTrack*LeftTrackToSet, UTankTrack* RightTrackToSet);
private:
	UTankTrack * LeftTrack = nullptr;
	UTankTrack * RightTrack = nullptr;

	
};
