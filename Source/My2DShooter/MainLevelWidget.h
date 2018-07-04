// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"
#include "MainLevelScriptActor.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainLevelWidget.generated.h"

/**
 * 
 */
UCLASS()
class MY2DSHOOTER_API UMainLevelWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY()
		int MaxLevelFuel;

	UPROPERTY(Category = "MyLevelWidget", VisibleAnywhere, BlueprintReadWrite)
		int CurrLevelFuel;

public:
	
	UFUNCTION()
		void SetMaxFuel(int MaxFuel);

	UFUNCTION(BlueprintCallable)
		int GetMaxFuel();

	UFUNCTION()
		void SetCurrentFuel(int CurrentFuelNum);

};
