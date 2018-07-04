// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MineActor.h"


// Sets default values
AMineActor::AMineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MineMesh(TEXT("/Game/TwinStick/Meshes/Rollermine"));
	// Create the mesh component
	MineMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MineMesh"));
	RootComponent = MineMeshComponent;
	MineMeshComponent->SetCollisionProfileName("Mine");
	MineMeshComponent->SetStaticMesh(MineMesh.Object);

}

// Called when the game starts or when spawned
void AMineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

