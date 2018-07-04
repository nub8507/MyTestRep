// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"
#include "MainLevelScriptActor.h"

#include "CoreMinimal.h"
#include "MainPawn.h"
#include "MainPlayerPawn.generated.h"


UCLASS(Blueprintable)
class MY2DSHOOTER_API AMainPlayerPawn : public AMainPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPlayerPawn();

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadOnly)
		FString PlayerProjectileName;


	/* Handler for the fire timer expiry */
	static const FName FireAction;
	static const FName MenuAction;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

private:

	uint32 bCanFire : 1;

	void ShotTimerExpired();

	void FireActionPress();

	void MenuActionPress();

	void FireShot(FVector FireDirection, float FireSpeed);

	float LastMovement;

	void ExecMove(float DeltaTime);

	TSubclassOf<class UObject> FindOrLoadBluePrintClass(const TCHAR * path);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
