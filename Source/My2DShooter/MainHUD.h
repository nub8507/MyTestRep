// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"
#include "MainLevelScriptActor.h"

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class MY2DSHOOTER_API AMainHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	AMainHUD(const FObjectInitializer& ObjectInitializer);

	virtual void DrawHUD() override;
	
	float UIScale;

protected:

	void DrawHealthBar(AActor* ForActor, float HealthPercentage, int32 BarHeight, int32 OffsetY) const;

	void DrawActorsHealth();

	APlayerController* GetPlayerController() const;

	UPROPERTY()
		class UTexture2D* EnemyTeamHPTexture;

	UPROPERTY()
		class UTexture2D* BarFillTexture;
};
