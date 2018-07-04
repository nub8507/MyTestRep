// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include "Engine.h"

#include "Struct.h"
#include "MainLevelClass.h"

#include "MainLevelScriptActor.generated.h"

UCLASS(notplaceable, meta = (KismetHideOverrides = "ReceiveAnyDamage,ReceivePointDamage,ReceiveRadialDamage,ReceiveActorBeginOverlap,ReceiveActorEndOverlap,ReceiveHit,ReceiveDestroyed,ReceiveActorBeginCursorOver,ReceiveActorEndCursorOver,ReceiveActorOnClicked,ReceiveActorOnReleased,ReceiveActorOnInputTouchBegin,ReceiveActorOnInputTouchEnd,ReceiveActorOnInputTouchEnter,ReceiveActorOnInputTouchLeave"), HideCategories = (Collision, Rendering, "Utilities|Transformation"))
class MY2DSHOOTER_API AMainLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:

	AMainLevelScriptActor();

	virtual void PreInitializeComponents() override;

	UPROPERTY(Category = "MyLevelData", VisibleAnywhere, BlueprintReadOnly) 
		AMainLevelClass* LevelClass;

	static TSubclassOf<class UObject> FindOrLoadBluePrintClass(const TCHAR* path);

	static FVector GetRandomPos(FVector Min, FVector Max);

	virtual void Tick(float DeltaTime) override;

};
