// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainLevelClass.h"
#include "MainLevelScriptActor.h"

// Sets default values
AMainLevelClass::AMainLevelClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainLevelClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainLevelClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

