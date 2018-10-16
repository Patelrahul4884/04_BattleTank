// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
//forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankAimingComponent;
class UTankNavMovementComponent;
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();
public:
	
	UFUNCTION(BlueprintCallable,Category=Setup)
	void SetBarrelReference(UTankBarrel*BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret*TurretToSet);

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = firing)
	void Fire();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankNavMovementComponent* TankMovementComponent = nullptr;
private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	
	double LastFireTime = 0;
};
