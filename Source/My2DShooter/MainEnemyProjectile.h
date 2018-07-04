// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "MainLevelScriptActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainEnemyProjectile.generated.h"

UCLASS(Blueprintable)
class MY2DSHOOTER_API AMainEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainEnemyProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
