// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainPlayerPawn.h"

#include "MainPlayerProjectile.h"
#include "DoActorsHit.h"

const FName AMainPlayerPawn::FireAction("FireAction");
const FName AMainPlayerPawn::MenuAction("MenuAction");

// Sets default values
AMainPlayerPawn::AMainPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(45.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	this->SetHealth(100.f);
	this->SetMaxHealth(100.f);
	this->SetHealthEnabled(true);
}

void AMainPlayerPawn::ShotTimerExpired()
{
	bCanFire = true;
}

// Called when the game starts or when spawned
void AMainPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//
	this->ExecMove(DeltaTime);
	//
}

// Called to bind functionality to input
void AMainPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(FireAction, EInputEvent::IE_Pressed, this, &AMainPlayerPawn::FireActionPress);
	PlayerInputComponent->BindAction(MenuAction, EInputEvent::IE_Pressed, this, &AMainPlayerPawn::MenuActionPress).bExecuteWhenPaused = true;

}

void AMainPlayerPawn::FireActionPress()
{
	
	FVector mouseLocation, mouseDirection;
	APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();
	playerController->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);

	FVector CurrPos;
	CurrPos = GetActorLocation();

	FVector DistVector;
	DistVector = mouseLocation - CurrPos;

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(DistVector.X, DistVector.Y, 0.f).GetClampedToMaxSize(1.0f);
	MoveSpeed = DistVector.Size2D() * 200.f;

	if (LastMovement > 0.2f)
		FireShot(MoveDirection, MoveSpeed);

}

void AMainPlayerPawn::FireShot(FVector FireDirection, float FireSpeed)
{
	// If we it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				// spawn the projectile
				TSubclassOf<class AMainPlayerProjectile> aPlayerProjectile;
				const TCHAR* T = *(this->PlayerProjectileName);
				aPlayerProjectile = FindOrLoadBluePrintClass(T);
				AMainPlayerProjectile* Proj;
				Proj = World->SpawnActor<AMainPlayerProjectile>(aPlayerProjectile.Get(), SpawnLocation, FireRotation);
				Proj->InitSpeed(FireSpeed);
//				Proj->MaxSpeed = FireSpeed;
			}

		}
	}
}

void AMainPlayerPawn::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{

	if ((OtherActor == nullptr) || (OtherActor == this) || (OtherComponent == nullptr))
		return;

	UDoActorsHit::ExecActorHit(this, OtherActor, 0);

}

void AMainPlayerPawn::ExecMove(float DeltaTime)
{
	//
	FVector mouseLocation, mouseDirection;
	APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();
	playerController->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);


	FVector CurrPos;
	CurrPos = GetActorLocation();

	FVector DistVector;
	DistVector = mouseLocation - CurrPos;

		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::White, FString::Printf(TEXT("DeltaMove: %f,  "), DistVector.Size2D()) + mouseLocation.ToString() + "  " + CurrPos.ToString());
//	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::White, FString::Printf(TEXT("DeltaMove: %f,%f  "), mouseLocation.X- CurrPos.X, mouseLocation.Y - CurrPos.Y) + mouseLocation.ToString() + "  " + mouseDirection.ToString());

//	return;

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(DistVector.X, DistVector.Y, 0.f).GetClampedToMaxSize(1.0f);
	MoveSpeed = DistVector.Size2D() * 200.f;

//	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::White, MoveDirection.ToString() + "  " + mouseLocation.ToString() + "  " + CurrPos.ToString());

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaTime;

	// If non-zero size, move this actor
	if (Movement.Size() > 0.2f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	LastMovement = Movement.Size();
	//
}

TSubclassOf<class UObject> AMainPlayerPawn::FindOrLoadBluePrintClass(const TCHAR* path)
{

	UObject* something = StaticLoadObject(UObject::StaticClass(), nullptr, path);
	UBlueprint* bp = Cast<UBlueprint>(something);
	TSubclassOf<class UObject> MyItemBlueprint;
	MyItemBlueprint = (UClass*)bp->GeneratedClass;

	return MyItemBlueprint;
}

void AMainPlayerPawn::MenuActionPress()
{
	//
	APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();
	if (playerController != NULL)
	{
		playerController->SetPause(!playerController->IsPaused());
	}
	//
}
