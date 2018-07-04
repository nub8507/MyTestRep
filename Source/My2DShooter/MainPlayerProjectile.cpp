// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainPlayerProjectile.h"


// Sets default values
AMainPlayerProjectile::AMainPlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->BaseProjectileMovement = nullptr;
//	this->Damage = 0;

}

// Called when the game starts or when spawned
void AMainPlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainPlayerProjectile::InitSpeed2()
{
	if (!(this->BaseProjectileMovement == nullptr)) {
		this->BaseProjectileMovement->InitialSpeed = this->InitialSpeed;
		this->BaseProjectileMovement->MaxSpeed = this->MaxSpeed;
	}
}

// Called every frame
void AMainPlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMainPlayerProjectile::GetProjectileDamage()
{
	return this->Damage;
}

void AMainPlayerProjectile::InitSpeed(float Speed)
{
	//
	this->InitialSpeed = Speed;
	this->MaxSpeed = Speed;
	//
	if (!(this->BaseProjectileMovement == nullptr)) {
		this->BaseProjectileMovement->InitialSpeed = Speed;
		this->BaseProjectileMovement->MaxSpeed = Speed;
	}

	//
}

void AMainPlayerProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{

	if ((OtherActor == nullptr) || (OtherActor == this) || (OtherComponent == nullptr))
		return;

	UDoActorsHit::ExecActorHit(this, OtherActor, 0);

}

