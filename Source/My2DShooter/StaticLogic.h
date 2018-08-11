// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct.h"
#include "UObject/NoExportTypes.h"
#include "StaticLogic.generated.h"

/**
 * 
 */
UCLASS()
class MY2DSHOOTER_API UStaticLogic : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
		static FVector GetRandomPos(FVector Min, FVector Max);

	UFUNCTION()
		static FVector GetRandomPos(FMyGameZone Zone);

	
};
