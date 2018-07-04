// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"

//#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Struct.h"

#include "MainLevelClass.generated.h"

class AMainLevelScriptActor;
class UMainLevelWidget;
class AMainMineActor;
class AMainFoodActor;
class AMainEnemyCharacter;


UCLASS()
class MY2DSHOOTER_API AMainLevelClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainLevelClass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		TArray<AMainMineActor*>MineList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		TArray<AMainFoodActor*>FoodList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		TArray<FMyEnemy>InitEnemyList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyLevelData")
		TArray<AMainEnemyCharacter*>EnemyList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = "MyLevelData", VisibleAnywhere, BlueprintReadOnly)
		UMainLevelWidget* LevelWidget;

	UPROPERTY(Category = "MyLevelData", VisibleAnywhere, BlueprintReadOnly)
		FVector MaxLevelSizePos;

	UPROPERTY(Category = "MyLevelData", VisibleAnywhere, BlueprintReadOnly)
		FVector MinLevelSizePos;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
