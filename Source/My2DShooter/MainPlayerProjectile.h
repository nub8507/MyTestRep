// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EngineMinimal.h"
#include "MainLevelScriptActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainPlayerProjectile.generated.h"

UCLASS(Blueprintable)
class MY2DSHOOTER_API AMainPlayerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainPlayerProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Gameplay, BlueprintReadWrite, EditDefaultsOnly)
		float Damage;

	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadOnly)
		float InitialSpeed;

	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadOnly)
		float MaxSpeed;

	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* BaseProjectileMovement;

	UFUNCTION(BlueprintCallable)
		void InitSpeed2();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual float GetProjectileDamage();

	virtual void InitSpeed(float Speed);

	UFUNCTION(BlueprintCallable)
		virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

private:

};
