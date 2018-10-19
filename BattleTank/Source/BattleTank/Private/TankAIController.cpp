// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank =GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank&&ControlledTank)) { return; }
	{
		//TODO move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);
		//aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		//fire if ready
		AimingComponent->Fire();
	}
}

