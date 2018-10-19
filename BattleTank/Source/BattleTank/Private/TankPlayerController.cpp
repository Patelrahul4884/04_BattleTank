                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               // Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "TankAimingComponent.h"
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
		FoundAimingComponent(AimingComponent);
	
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}
void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FVector HitLocation;//out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		AimingComponent->AimAt(HitLocation);
	}
}
//get world location through location and line traced, true if hit lnadscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX*CrosshairXLocation, ViewPortSizeY*CrosshairYLocation);
	
	FVector LookDirection;
	if(GetLookDirection(ScreenLocation,LookDirection))
	{
		// line trace along that look direction ,and see what we hit(up to max range)
		GetLookVectorHitLocation(LookDirection,HitLocation);
	}
	return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector&HitLocation) const
{
	FHitResult Hitresult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
		Hitresult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
		{
		HitLocation= Hitresult.Location;
			return true;
		}
	HitLocation = FVector(0);
	return false;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector&LookDirection) const
{
	//"de project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

