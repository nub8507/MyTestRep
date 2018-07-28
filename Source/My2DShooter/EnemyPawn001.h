// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainEnemyCharacter.h"

#include "EnemyPawn001.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MY2DSHOOTER_API AEnemyPawn001 : public AMainEnemyCharacter
{
	GENERATED_BODY()
	

private:
	FVector Speed;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	AEnemyPawn001();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
//	UFUNCTION(BlueprintCallable)
	virtual void ExecMove(float DeltaTime) override;

	virtual void GetDamage(float Damage) override;

	UFUNCTION(BlueprintCallable)
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	virtual void StartDestroyEnemy() override;
};
