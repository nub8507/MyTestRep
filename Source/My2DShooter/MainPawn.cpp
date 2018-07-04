// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainPawn.h"


// Sets default values
AMainPawn::AMainPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Health = 0.f;
	this->MaxHealth = 0.f;
	this->HealthEnabled = false;
}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMainPawn::GetHealth()
{
	return this->Health;
}

float AMainPawn::GetMaxHealth()
{
	return this->MaxHealth;
}

void AMainPawn::SetHealth(float InitHealth)
{
	this->Health = InitHealth;
}

void AMainPawn::SetMaxHealth(float InitMaxHealth)
{
	this->MaxHealth = InitMaxHealth;
}

bool AMainPawn::IsHealthEnabled()
{
	return this->HealthEnabled;
}

void AMainPawn::SetHealthEnabled(bool HealthStatus)
{
	this->HealthEnabled = HealthStatus;
}

