// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "EnemyPawn001.h"

#include "MainEnemyCharacter.h"
#include "MainPlayerProjectile.h"

AEnemyPawn001::AEnemyPawn001()
{
//	this->PlayerActor = Cast<AMy2DShooterPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	this->SetHealth(1000.0f);
	this->SetMaxHealth(1000.0f);
	this->SetHealthEnabled(true);
	this->HPRecovery = 0.0f;

	Speed = this->GenerateInitSpeed(FVector(-1.0f, -1.0f, 0.0f), FVector(1.0f, 1.0f, 0.0f));
	this->DestroyScore = 100;

}

void AEnemyPawn001::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemyPawn001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//
	this->ExecMove(DeltaTime);
}

void AEnemyPawn001::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyPawn001::ExecMove(float DeltaTime)
{
	Super::ExecMove(DeltaTime);
	//
	FHitResult Hit(1.f);
	FVector Movement = Speed.GetSafeNormal2D()*DeltaTime*200.f;
	RootComponent->MoveComponent(Movement, Movement.Rotation(),true,&Hit);

	if (Hit.IsValidBlockingHit())
	{
		const UObject *HitActor = Hit.GetActor();

		if ((Cast<AMainPlayerProjectile>(HitActor) != nullptr) || HitActor == nullptr) 
			return;
		//
		const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
		const FVector V1 = FVector::VectorPlaneProject(Speed.GetSafeNormal2D(), Normal2D);
		const FVector NewSpeed = -Speed + V1*2.f;
		const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
//		RootComponent->MoveComponent(Deflection, FRotator(0.f), true);
		this->Speed = NewSpeed.GetSafeNormal2D();
	}
}

void AEnemyPawn001::GetDamage(float Damage)
{
	this->ChangeHP(-Damage);
	if (this->GetHealth() <= 0) {
		this->StartDestroyEnemy();
		this->Destroy();
	}
}

void AEnemyPawn001::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{

	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::White, FString::Printf(TEXT("DeltaMove: %f,  "), Speed.Size2D()) + "  " + Hit.Normal.ToString() + "  " + Hit.ImpactPoint.ToString());

	return;

	FVector Normal = Hit.Normal;

	Normal.Z = 0;
	float T = Speed.X*Normal.X + Speed.Y*Normal.Y;
	float T2 = Speed.X*Speed.X + Speed.Y*Speed.Y;
	FVector NewSpeed = 2 * (T / T2)*Normal - Speed;

	NewSpeed.Normalize();

	this->Speed = NewSpeed;
}

void AEnemyPawn001::StartDestroyEnemy()
{
	Super::StartDestroyEnemy();
}
