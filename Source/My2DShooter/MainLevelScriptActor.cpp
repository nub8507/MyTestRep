// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainLevelScriptActor.h"

#include "MainLevelWidget.h"

// Called when the game starts or when spawned
AMainLevelScriptActor::AMainLevelScriptActor()
{
	//
	this->LevelClass = nullptr;
	//
}


void AMainLevelScriptActor::PreInitializeComponents()
{
	Super::PreInitializeComponents();

}

TSubclassOf<class UObject> AMainLevelScriptActor::FindOrLoadBluePrintClass(const TCHAR* path)
{

	UObject* something = StaticLoadObject(UObject::StaticClass(), nullptr, path);

	if (something == nullptr) return nullptr;

	TSubclassOf<class UObject> MyItemBlueprint;
	MyItemBlueprint = (UClass*)something;

	return MyItemBlueprint;
}

FVector AMainLevelScriptActor::GetRandomPos(FVector Min, FVector Max)
{
	float X = FMath::RandRange(Min.X, Max.X);
	float Y = FMath::RandRange(Min.Y, Max.Y);
	float Z = FMath::RandRange(Min.Z, Max.Z);
	//	
	return FVector(X, Y, Z);
}

// Called every frame
void AMainLevelScriptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
