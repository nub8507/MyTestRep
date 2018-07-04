// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Struct.h"
#include "EngineMinimal.h"
#include "EnemySpawnActor.generated.h"

class AMainLevelScriptActor;
class AMainEnemyCharacter;

UCLASS(Blueprintable, Category = "My BP")
class MY2DSHOOTER_API AEnemySpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
//	UPROPERTY()
//	AMainLevelScriptActor* LevelClass;

//	UFUNCTION()
//	void AddEnemyToList(int32 Type,int32 Num);

private:
	
	UPROPERTY()
	float TimeAfterSpawn;

	UPROPERTY()
	AMainLevelScriptActor* Level;

	UFUNCTION()
	int32 FindNextEnemyToSpawn();

	UFUNCTION()
	void CastNextEnemy(int32 EnemyNum);

	UFUNCTION()
	TSubclassOf<class UObject> GetEnemyByNum(int32 EnemyNum);

	UWorld* World;
};
