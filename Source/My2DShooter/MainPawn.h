// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainPawn.generated.h"

UCLASS()
class MY2DSHOOTER_API AMainPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		float Health;

	UPROPERTY()
		float MaxHealth;

	UPROPERTY()
		bool HealthEnabled;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		float GetHealth();
	
	UFUNCTION()
		float GetMaxHealth();

	UFUNCTION()
		void SetHealth(float InitHealth);

	UFUNCTION()
		void SetMaxHealth(float InitMaxHealth);

	UFUNCTION()
		bool IsHealthEnabled();

	UFUNCTION()
		void SetHealthEnabled(bool HealthStatus);
};
