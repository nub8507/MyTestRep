// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "FoodActor.h"


// Sets default values
AFoodActor::AFoodActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoodMesh(TEXT("/Game/TwinStick/Meshes/oil_barrel"));
	// Create the mesh component
	FoodMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMesh"));
	RootComponent = FoodMeshComponent;
	FoodMeshComponent->SetCollisionProfileName("Food");
	FoodMeshComponent->SetStaticMesh(FoodMesh.Object);

}

// Called when the game starts or when spawned
void AFoodActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFoodActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

