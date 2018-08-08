// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "MainLevelClass.h"
#include "InitLevelClass.generated.h"

class AMainLevelScriptActor;

UCLASS(Blueprintable)
class MY2DSHOOTER_API AInitLevelClass : public AMainLevelClass
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInitLevelClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//	UPROPERTY(Category = "MyLevelData", VisibleAnywhere, BlueprintReadOnly)
	bool DataLoaded;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		int EatCount;
	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		int MineCount;
	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		int LevelType;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FVector MaxLevelSize;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FVector MinLevelSize;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FString PlayerClassName;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FVector PlayerStartPosition;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FString PlayerProjectileName;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FString MineActorName;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FString FoodActorName;

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadWrite)
		FString HUDMenuName;


//	UFUNCTION(BlueprintCallable, Category = "MyLevelData")
	UFUNCTION()
	void InitLevelData();

	UPROPERTY(Category = "MyLevelData", EditAnywhere, BlueprintReadOnly)
	TArray<struct FMyEnemy>EnemySpawnList;


private:
	UFUNCTION()
		bool InitEat();

	UFUNCTION()
		bool InitMine();

	UFUNCTION()
		bool InitEnemyGate();

	UFUNCTION()
		bool InitLevelMenu();

	UFUNCTION()
		bool InitPlayer();

	UFUNCTION()
	FVector GetRandomPos(FVector Min, FVector Max);
	
	FRotator GetRandomRot(FRotator Min, FRotator Max);

	float GateDelay;
	bool initEat;
	bool initMine;
	bool initEnemyGate;
	bool initPlayer;
	bool initLevelMenu;

	void CopyEnemyList();

	AMainLevelScriptActor* Level;
};
