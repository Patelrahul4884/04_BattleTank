// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum of aiming state
UENUM()
enum class EAimingColorAction : uint8
{
	Reloading,
	Aiming,
	Locked
};
//forward declaration
class UTankBarrel;
class UTankTurret; 
class AProjectile;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel*BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "firing")
		void Fire();
private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrel(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;
	double LastFireTime = 0;

	
protected: 
	UPROPERTY(BlueprintReadOnly, Category="State")
	EAimingColorAction AimAction = EAimingColorAction::Aiming;
};