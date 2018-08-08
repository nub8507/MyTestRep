// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "DoActorsHit.h"

#include "MainMenuWidget.h"
#include "MainPlayerProjectile.h"
#include "MainMineActor.h"
#include "MainPlayerPawn.h"
#include "MainFoodActor.h"
#include "EnemySpawnActor.h"
#include "MainEnemyProjectile.h"
#include "MainEnemyCharacter.h"
//#include "MainLevelClass.h"


void UDoActorsHit::ExecPlayerMinePawnHit(AActor* Source, AActor* Dest, int DestType) {
	//
	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(Source->GetWorld()));
	MyPlayer->SetPause(true);
	TSubclassOf<class UUserWidget> wMainMenu;
	wMainMenu = AMainLevelScriptActor::FindOrLoadBluePrintClass(TEXT("Blueprint'/Game/TwinStick/Wigets/MainMenuWidget.MainMenuWidget_C'"));
	UMainMenuWidget* UW = CreateWidget<UMainMenuWidget>(MyPlayer, wMainMenu);
	if (UW)
	{
		UW->AddToViewport(9999);
		//
		FInputModeGameAndUI Mode;
		Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
		Mode.SetHideCursorDuringCapture(true);
		MyPlayer->SetInputMode(Mode);
		MyPlayer->bShowMouseCursor = true;
		MyPlayer->SetPause(true);
	}
	Source->Destroy();
}

void UDoActorsHit::ExecPlayerFoodPawnHit(AActor* Source, AActor* Dest, int DestType) {
	//
	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(Source->GetWorld()));
	//
	AMainLevelScriptActor *Level = Cast<AMainLevelScriptActor>(MyPlayer->GetLevel()->GetLevelScriptActor());
	for (int i = 0; i < Level->LevelClass->FoodList.Num(); i++)
	{
		if (Level->LevelClass->FoodList[i] == Dest) {
			Level->LevelClass->FoodList.RemoveAt(i);
			return;
		}
	}
	//
	Dest->Destroy();
}

void UDoActorsHit::ExecPlayerEnemyPawnHit(AActor* Source, AActor* Dest, int DestType) {
	//
	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(Source->GetWorld()));
	MyPlayer->SetPause(true);
	TSubclassOf<class UUserWidget> wMainMenu;
	wMainMenu = AMainLevelScriptActor::FindOrLoadBluePrintClass(TEXT("Blueprint'/Game/TwinStick/Wigets/MainMenuWidget.MainMenuWidget_C'"));
	UMainMenuWidget* UW = CreateWidget<UMainMenuWidget>(MyPlayer, wMainMenu);
	if (UW)
	{
		UW->AddToViewport(9999);
		//
		FInputModeGameAndUI Mode;
		Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
		Mode.SetHideCursorDuringCapture(true);
		MyPlayer->SetInputMode(Mode);
		MyPlayer->bShowMouseCursor = true;
		MyPlayer->SetPause(true);
	}
	//
	Source->Destroy();
	//
}

void UDoActorsHit::ExecPlayerEnemyProjectilePawnHit(AActor* Source, AActor* Dest, int DestType) {
	//
	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(Source->GetWorld()));
	MyPlayer->SetPause(true);
	TSubclassOf<class UUserWidget> wMainMenu;
	wMainMenu = AMainLevelScriptActor::FindOrLoadBluePrintClass(TEXT("Blueprint'/Game/TwinStick/Wigets/MainMenuWidget.MainMenuWidget_C'"));
	UMainMenuWidget* UW = CreateWidget<UMainMenuWidget>(MyPlayer, wMainMenu);
	if (UW)
	{
		UW->AddToViewport(9999);
		//
		FInputModeGameAndUI Mode;
		Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
		Mode.SetHideCursorDuringCapture(true);
		MyPlayer->SetInputMode(Mode);
		MyPlayer->bShowMouseCursor = true;
		MyPlayer->SetPause(true);
	}
	//
	Source->Destroy();
	//
}

void UDoActorsHit::ExecPlayerWallPawnHit(AActor* Source, AActor* Dest, int DestType) {
	//
	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(Source->GetWorld()));
	MyPlayer->SetPause(true);
	TSubclassOf<class UUserWidget> wMainMenu;
	wMainMenu = AMainLevelScriptActor::FindOrLoadBluePrintClass(TEXT("Blueprint'/Game/TwinStick/Wigets/MainMenuWidget.MainMenuWidget_C'"));
	UMainMenuWidget* UW = CreateWidget<UMainMenuWidget>(MyPlayer, wMainMenu);
	if (UW)
	{
		UW->AddToViewport(9999);
		//
		FInputModeGameAndUI Mode;
		Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
		Mode.SetHideCursorDuringCapture(true);
		MyPlayer->SetInputMode(Mode);
		MyPlayer->bShowMouseCursor = true;
//		MyPlayer->SetPause(true);
	}
	//
	Source->Destroy();
	//
}

void UDoActorsHit::ExecPlayerProjEnemyPawnHit(AActor * Source, AActor * Dest, int DestType)
{
	AMainPlayerProjectile* S;
	S = Cast<AMainPlayerProjectile>(Source);
	AMainEnemyCharacter* D = Cast<AMainEnemyCharacter>(Dest);
	//
	float Damage = S->GetProjectileDamage();
	D->GetDamage(Damage);
	Source->Destroy();
}

void UDoActorsHit::ExecPlayerProjEnemyProjPawnHit(AActor * Source, AActor * Dest, int DestType)
{
	Source->Destroy();
	return;
}

void UDoActorsHit::ExecPlayerProjEnemySpawnActorHit(AActor * Source, AActor * Dest, int DestType)
{
	Source->Destroy();
	return;
}

void UDoActorsHit::ExecPlayerProjMineActorHit(AActor * Source, AActor * Dest, int DestType)
{
	Source->Destroy();
	return;
}

void UDoActorsHit::ExecPlayerProjWallPawnHit(AActor * Source, AActor * Dest, int DestType)
{
	Source->Destroy();
	return;
}


void UDoActorsHit::ExecActorHit(AActor * Source, AActor * Dest, int DestType)
{
//	return;

	if (Cast<AMainPlayerPawn>(Source) != nullptr) {
		if (Cast<AMainMineActor>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerMinePawnHit(Source, Dest, 0);
		else if (Cast<AMainFoodActor>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerFoodPawnHit(Source, Dest, 0);
		else if (Cast<AMainEnemyCharacter>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerEnemyPawnHit(Source, Dest, 0);
		else if (Cast<AMainEnemyProjectile>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerEnemyProjectilePawnHit(Source, Dest, 0);
		else if (Dest->IsA(AEnemySpawnActor::StaticClass()))
			UDoActorsHit::ExecPlayerEnemyPawnHit(Source, Dest, 0);
		else
			UDoActorsHit::ExecPlayerWallPawnHit(Source, Dest, 0);
	}
	else if (Cast<AMainPlayerPawn>(Dest) != nullptr) {
		if (Cast<AMainMineActor>(Source) != nullptr)
			UDoActorsHit::ExecPlayerEnemyProjectilePawnHit(Dest, Source, 0);
		else if (Cast<AMainFoodActor>(Source) != nullptr)
			UDoActorsHit::ExecPlayerFoodPawnHit(Dest, Source, 0);
		else if (Source->IsA(AEnemySpawnActor::StaticClass())) 
			UDoActorsHit::ExecPlayerEnemyPawnHit(Dest, Source, 0);
		else if (Cast<AMainEnemyCharacter>(Source) != nullptr) 
			UDoActorsHit::ExecPlayerEnemyPawnHit(Dest, Source, 0);
		else if (Cast<AMainEnemyProjectile>(Source) != nullptr)
			UDoActorsHit::ExecPlayerEnemyProjectilePawnHit(Dest, Source, 0);
		else
			UDoActorsHit::ExecPlayerWallPawnHit(Dest, Source, 0);
	}
	else if (Cast<AMainPlayerProjectile>(Source) != nullptr){
		if (Cast<AMainEnemyCharacter>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerProjEnemyPawnHit(Source, Dest, 0);
		else if (Cast<AMainEnemyProjectile>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerProjEnemyProjPawnHit(Source, Dest, 0);
		else if (Dest->IsA(AEnemySpawnActor::StaticClass()))
			UDoActorsHit::ExecPlayerProjEnemySpawnActorHit(Source, Dest, 0);
		else if (Cast<AMainMineActor>(Dest) != nullptr)
			UDoActorsHit::ExecPlayerProjMineActorHit(Source, Dest, 0);
		else
			UDoActorsHit::ExecPlayerProjWallPawnHit(Source, Dest, 0);
	}
	else if (Cast<AMainPlayerProjectile>(Dest) != nullptr) {
		if (Cast<AMainEnemyCharacter>(Source) != nullptr)
			UDoActorsHit::ExecPlayerProjEnemyPawnHit(Dest, Source, 0);
		else if (Cast<AMainEnemyProjectile>(Source) != nullptr)
			UDoActorsHit::ExecPlayerProjEnemyProjPawnHit(Dest, Source, 0);
		else if (Source->IsA(AEnemySpawnActor::StaticClass()))
			UDoActorsHit::ExecPlayerProjEnemySpawnActorHit(Dest, Source, 0);
		else if (Cast<AMainMineActor>(Source) != nullptr)
			UDoActorsHit::ExecPlayerProjMineActorHit(Dest, Source, 0);
		else
			UDoActorsHit::ExecPlayerProjWallPawnHit(Dest, Source, 0);
	}

}
