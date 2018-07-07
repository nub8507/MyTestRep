// Fill out your copyright notice in the Description page of Project Settings.


//#include "My2DShooter.h"
#include "InitLevelClass.h"

#include "MainLevelWidget.h"
#include "MainMineActor.h"
#include "MainFoodActor.h"
#include "EnemySpawnActor.h"
#include "MainPlayerPawn.h"
#include "MainHUD.h"

// Sets default values
AInitLevelClass::AInitLevelClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//
	this->DataLoaded = false;
	this->GateDelay = 5;
	this->initEat = false;
	this->initMine = false;
	this->initEnemyGate = false;
	this->initPlayer = false;
	//
}

// Called when the game starts or when spawned
void AInitLevelClass::BeginPlay()
{
	Super::BeginPlay();

	this->FoodList.Empty();
	this->MineList.Empty();
	this->InitEnemyList.Empty();
	this->EnemyList.Empty();
	//
	Level = Cast<AMainLevelScriptActor>(GetLevel()->GetLevelScriptActor());
	Level->LevelClass = this;
	//
	this->LevelWidget = nullptr;
	//
	this->InitLevelData();
	//
}

// Called every frame
void AInitLevelClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!initEnemyGate)
		this->GateDelay -= DeltaTime;

	if (!this->DataLoaded)
		this->InitLevelData();

	if (this->LevelWidget != nullptr) {
		int t1 = this->LevelWidget->GetMaxFuel();
		int t2 = this->FoodList.Num();
		this->LevelWidget->SetCurrentFuel(this->LevelWidget->GetMaxFuel()- this->FoodList.Num());
	}

}

void AInitLevelClass::InitLevelData()
{
	if (!initEat)
		initEat = this->InitEat();

	if (!initMine)
		initMine = this->InitMine();

	if (!initEnemyGate&&GateDelay < 0)
		initEnemyGate = this->InitEnemyGate();

	if (!initPlayer)
		initPlayer = InitPlayer();

	if (!initLevelMenu)
		initLevelMenu = InitLevelMenu();

	if (initMine&&initEat&&initEnemyGate&&initPlayer&&initLevelMenu)
		this->DataLoaded = true;

	this->MaxLevelSizePos = this->MaxLevelSize;
	this->MinLevelSizePos = this->MinLevelSize;
	
}

bool AInitLevelClass::InitEat()
{
	//
	UWorld* const World = GetWorld();
	FVector NewPos;
	AMainFoodActor* NewActor;
	TSubclassOf<class AMainFoodActor> aFoodActor;
	const TCHAR* T = *(this->FoodActorName);
	aFoodActor = AMainLevelScriptActor::FindOrLoadBluePrintClass(T);

	if (aFoodActor == nullptr) return true;
	//
	for (int i = 0; i < this->EatCount; i++)
	{
		NewPos = GetRandomPos(this->MinLevelSize, this->MaxLevelSize);
		NewActor = World->SpawnActor<AMainFoodActor>(aFoodActor.Get(), NewPos, NewPos.Rotation());
//		NewActor->SetActorScale3D(FVector(2.f, 2.f, 2.f));
		NewActor->InitRotation = GetRandomRot(FRotator(-50, -50, -50), FRotator(50, 50, 50));
		this->FoodList.Add(NewActor);
	}
	return true;
	//
}

bool AInitLevelClass::InitMine()
{
	//
	UWorld* const World = GetWorld();
	FVector NewPos;
	AMainMineActor* NewActor;
	//
	TSubclassOf<class AMainMineActor> aMineActor;
	const TCHAR* T = *(this->MineActorName);
	aMineActor = AMainLevelScriptActor::FindOrLoadBluePrintClass(T);
	if (aMineActor == nullptr) return true;

	for (int i = 0; i < this->MineCount; i++)
	{
		NewPos = GetRandomPos(this->MinLevelSize, this->MaxLevelSize);
		NewActor = World->SpawnActor<AMainMineActor>(aMineActor.Get(),NewPos, NewPos.Rotation());
		NewActor->InitRotation = GetRandomRot(FRotator(-50, -50, -50), FRotator(50, 50, 50));

		this->MineList.Add(NewActor);
	}
	return true;
	//
}

bool AInitLevelClass::InitEnemyGate()
{
	//
	UWorld* const World = GetWorld();
	FVector NewPos;
	AEnemySpawnActor* NewActor;
	//
	NewPos = GetRandomPos(this->MinLevelSize,this->MaxLevelSize);
	TSubclassOf<class AEnemySpawnActor> aEnemySpawnActor;
	aEnemySpawnActor = AMainLevelScriptActor::FindOrLoadBluePrintClass(TEXT("/Game/TwinStick/Actors/BP_EnemySpawnActor"));
	if (aEnemySpawnActor == nullptr) return true;

	NewActor = World->SpawnActor<AEnemySpawnActor>(aEnemySpawnActor.Get(), NewPos, NewPos.Rotation());
	//
	CopyEnemyList();
	//
	return true;
	//
}

bool AInitLevelClass::InitLevelMenu()
{
	APlayerController* MyPlayer = (APlayerController*)GetWorld()->GetFirstPlayerController();
	TSubclassOf<class UUserWidget> wLevelMenu;
	//
	wLevelMenu = AMainLevelScriptActor::FindOrLoadBluePrintClass(TEXT("/Game/TwinStick/Wigets/LevelInterface"));
	UMainLevelWidget* UW = CreateWidget<UMainLevelWidget>(MyPlayer, wLevelMenu);
	if (UW)
	{
		UW->SetMaxFuel(this->EatCount);
		UW->AddToViewport(1);
		this->LevelWidget = UW;
		return true;
	}
	//
	return false;
}

FVector AInitLevelClass::GetRandomPos(FVector Min,FVector Max)
{
	float X = FMath::RandRange(Min.X, Max.X);
	float Y = FMath::RandRange(Min.Y, Max.Y);
	float Z = FMath::RandRange(Min.Z, Max.Z);
	//	
	return FVector(X, Y, Z);
}

FRotator AInitLevelClass::GetRandomRot(FRotator Min, FRotator Max)
{
	float Yaw = FMath::RandRange(Min.Yaw, Max.Yaw);
	float Pitch = FMath::RandRange(Min.Pitch, Max.Pitch);
	float Roll = FMath::RandRange(Min.Roll, Max.Roll);
	//	
	return FRotator(Pitch, Yaw, Roll);
}

/*TSubclassOf<class UObject> AInitLevelClass::FindOrLoadBluePrintClass(const TCHAR* path)
{

	UObject* something = StaticLoadObject(UObject::StaticClass(), nullptr, path);
	UBlueprint* bp = Cast<UBlueprint>(something);
	if (bp == nullptr) return nullptr;
	TSubclassOf<class UObject> MyItemBlueprint;
	MyItemBlueprint = CastChecked<UClass>(bp->GeneratedClass);

	return MyItemBlueprint;
}*/

void AInitLevelClass::CopyEnemyList()
{
	//
	for (int32 i = 0; i < this->EnemySpawnList.Num(); i++)
		this->InitEnemyList.Add(this->EnemySpawnList[i]);
	//
}

bool AInitLevelClass::InitPlayer()
{
	//
	UWorld* const World = GetWorld();
	FVector NewPos;
	AMainPlayerPawn* NewActor;
	//
	TSubclassOf<class AMainPlayerPawn> aPlayerActor;
	const TCHAR* T = *(this->PlayerClassName);
	aPlayerActor = AMainLevelScriptActor::FindOrLoadBluePrintClass(T);
	if (aPlayerActor == nullptr) return true;
	NewActor = World->SpawnActor<AMainPlayerPawn>(aPlayerActor.Get(), this->PlayerStartPosition, this->PlayerStartPosition.Rotation());
	//
	NewActor->PlayerProjectileName = this->PlayerProjectileName;
	NewActor->AutoPossessPlayer = EAutoReceiveInput::Player0;
	APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();
	playerController->SetPawn(NewActor);
	
	TSubclassOf<class AMainHUD> aHUD;
	const TCHAR* HUD= *(this->HUDMenuName);
	aHUD = AMainLevelScriptActor::FindOrLoadBluePrintClass(HUD);

	playerController->ClientSetHUD(aHUD);
	//
	return true;
	//
}
