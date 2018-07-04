// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainEnemyCharacter.h"

#include "MainLevelScriptActor.h"
#include "MainPlayerPawn.h"
#include "My2DShooterGameInstance.h"

// Sets default values
AMainEnemyCharacter::AMainEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->EnemyType = 0;
	this->PlayerActor = nullptr; //Cast<AMy2DShooterPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called when the game starts or when spawned
void AMainEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

FVector AMainEnemyCharacter::GenerateInitSpeed(FVector Min, FVector Max)
{

	float X = FMath::RandRange(Min.X, Max.X);
	float Y = FMath::RandRange(Min.Y, Max.Y);
	float Z = Min.Z;
	//	
	return FVector(X, Y, Z);

}

// Called every frame
void AMainEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RepairHP(DeltaTime);
}

// Called to bind functionality to input
void AMainEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainEnemyCharacter::GetDamage(float Damage)
{
	return;
}

void AMainEnemyCharacter::StartDestroyEnemy()
{

	AMainLevelScriptActor* Level;
	Level = Cast<AMainLevelScriptActor>(GetLevel()->GetLevelScriptActor());

	FMyEnemy T = Level->LevelClass->InitEnemyList[this->EnemyNumOfLevelClassList];
	if (T.EnemyCount > 0) {
		Level->LevelClass->InitEnemyList[this->EnemyNumOfLevelClassList].Spawned = false;
	}
	
	UMy2DShooterGameInstance *GI;

	GI = GetWorld()->GetGameInstance<UMy2DShooterGameInstance>();
	GI->ChangeScore(this->DestroyScore);

}

void AMainEnemyCharacter::ExecMove(float DeltaTime)
{
	return;
}

float AMainEnemyCharacter::ChangeHP(float HP)
{
	float CurrHP = this->GetHealth();
	CurrHP += HP;
	//
	if (CurrHP > this->GetMaxHealth())
		CurrHP = this->GetMaxHealth();
	else if (CurrHP < 0)
		CurrHP = 0;

	this->SetHealth(CurrHP);

	return CurrHP;
}

void AMainEnemyCharacter::RepairHP(float DeltaTime)
{
	//
	float CurrHP = this->GetHealth();
	CurrHP += DeltaTime*this->HPRecovery;
	//
	if (CurrHP > this->GetMaxHealth())
		CurrHP = this->GetMaxHealth();
	else if (CurrHP < 0)
		CurrHP = 0;

	this->SetHealth(CurrHP);
}

