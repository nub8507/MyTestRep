// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainEnemyProjectile.h"


// Sets default values
AMainEnemyProjectile::AMainEnemyProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

