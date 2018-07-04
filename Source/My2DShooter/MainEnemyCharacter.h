// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"

#include "MainPawn.h"
#include "MainEnemyCharacter.generated.h"

class AMainPlayerPawn;

UCLASS(Blueprintable)
class MY2DSHOOTER_API AMainEnemyCharacter : public AMainPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float HPRecovery;

	FVector GenerateInitSpeed(FVector Min, FVector Max);

	int DestroyScore;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetDamage(float Damage);

	virtual void StartDestroyEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		int EnemyType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		AMainPlayerPawn* PlayerActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		int EnemyNumOfLevelClassList;

	UFUNCTION()
		virtual void ExecMove(float DeltaTime);

//	UFUNCTION()
//		float GetCurrHP();

//	UFUNCTION()
//		float GetMaxHP();

	UFUNCTION()
		float ChangeHP(float HP);


private:

	void RepairHP(float DeltaTime);
};
