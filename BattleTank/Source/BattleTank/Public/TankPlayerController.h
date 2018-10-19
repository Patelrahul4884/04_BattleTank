// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
		UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
			void FoundAimingComponent(UTankAimingComponent*AimComRef);
private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector&LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector&HitLocation) const;
};
