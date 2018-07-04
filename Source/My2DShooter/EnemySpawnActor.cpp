// Fill out your copyright notice in the Description page of Project Settings.


//#include "My2DShooter.h"
#include "EnemySpawnActor.h"

#include "MainLevelScriptActor.h"
#include "MainEnemyCharacter.h"

// Sets default values
AEnemySpawnActor::AEnemySpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->TimeAfterSpawn = 0;

	Level = nullptr;

	World = nullptr;
}

// Called when the game starts or when spawned
void AEnemySpawnActor::BeginPlay()
{
	Super::BeginPlay();

	Level = Cast<AMainLevelScriptActor>(GetLevel()->GetLevelScriptActor());

	World = GetWorld();
}

// Called every frame
void AEnemySpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

//	LevelClass = Cast<AMainLevelScriptActor>(GetLevel()->GetLevelScriptActor());

	this->TimeAfterSpawn += DeltaTime;

	int32 NextEnemy = FindNextEnemyToSpawn();

	if (NextEnemy >= 0 && TimeAfterSpawn >= Level->LevelClass->InitEnemyList[NextEnemy].TimeSpawn) {
		CastNextEnemy(NextEnemy);
	}

	if (this->TimeAfterSpawn > 10000)
		this->TimeAfterSpawn = 0;
}

int32 AEnemySpawnActor::FindNextEnemyToSpawn()
{
	
	for (int32 i = 0; i < Level->LevelClass->InitEnemyList.Num(); i++)
	{
		if (!Level->LevelClass->InitEnemyList[i].Spawned) {
			return i;
		}
	}

	return -1;
}

void AEnemySpawnActor::CastNextEnemy(int32 EnemyNum)
{
	TSubclassOf<class UObject> aEnemySpawnActor;
	aEnemySpawnActor = this->GetEnemyByNum(Level->LevelClass->InitEnemyList[EnemyNum].Type);
	AMainEnemyCharacter* NewActor = World->SpawnActor<AMainEnemyCharacter>(aEnemySpawnActor.Get(), this->GetActorLocation(), this->GetActorRotation());
	Level->LevelClass->InitEnemyList[EnemyNum].Spawned = true;
	Level->LevelClass->InitEnemyList[EnemyNum].EnemyCount--;
	if (NewActor==nullptr)
		return;
	NewActor->EnemyNumOfLevelClassList = EnemyNum;
	TimeAfterSpawn = 0;
}

TSubclassOf<class UObject> AEnemySpawnActor::GetEnemyByNum(int32 EnemyNum)
{
	if (EnemyNum==1) {
		return Level->FindOrLoadBluePrintClass(TEXT("/Game/TwinStick/Actors/BP_EnemyPawn001"));
	}

	return nullptr;
}

