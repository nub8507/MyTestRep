// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"
#include "MainLevelScriptActor.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "My2DShooterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MY2DSHOOTER_API UMy2DShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:

	UPROPERTY()
		int Score;

public:

	UMy2DShooterGameInstance();

	UFUNCTION(BlueprintCallable)
		int ChangeScore(int Delta);

	UFUNCTION(BlueprintCallable)
		int GetScore();

	UFUNCTION(BlueprintCallable)
		void SetScore(int NewScore);

};
