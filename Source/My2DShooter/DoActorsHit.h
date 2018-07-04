// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include"Engine.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "DoActorsHit.generated.h"
/**
 * 
 */
UCLASS()
class MY2DSHOOTER_API UDoActorsHit : public UObject
{
	GENERATED_BODY()
	
	
public:
		
	UFUNCTION()
	static void ExecActorHit(AActor * Source, AActor * Dest, int DestType);

private:

	UFUNCTION()
		static  void ExecPlayerMinePawnHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerFoodPawnHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerEnemyPawnHit(AActor * Source, AActor * Dest, int DestType);
	
	UFUNCTION()
		static void ExecPlayerEnemyProjectilePawnHit(AActor* Source, AActor* Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerWallPawnHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerProjEnemyPawnHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerProjEnemyProjPawnHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerProjEnemySpawnActorHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerProjMineActorHit(AActor * Source, AActor * Dest, int DestType);

	UFUNCTION()
		static void ExecPlayerProjWallPawnHit(AActor * Source, AActor * Dest, int DestType);


};
