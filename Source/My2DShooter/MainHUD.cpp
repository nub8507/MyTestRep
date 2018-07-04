// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainHUD.h"
#include "MainPawn.h"


AMainHUD::AMainHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> BarFillObj(TEXT("/Game/TwinStick/HUD/BarFill"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> EnemyTeamHealthBar(TEXT("/Game/TwinStick/HUD/EnemyTeamHealthBar"));
//	static ConstructorHelpers::FObjectFinder<UTexture2D> EnemyTeamHPObj(TEXT("/Game/UI/HUD/EnemyTeamHealthBar"));

//	static ConstructorHelpers::FObjectFinder<UTexture2D> DefaultActionObj(TEXT("/Game/UI/HUD/Actions/DefaultAction"));
//	static ConstructorHelpers::FObjectFinder<UTexture2D> DefaultCenterActionObj(TEXT("/Game/UI/HUD/Actions/DefaultActionBig"));
//	static ConstructorHelpers::FObjectFinder<UTexture2D> ActionPauseObj(TEXT("/Game/UI/HUD/Actions/ActionPause"));
//	static ConstructorHelpers::FObjectFinder<UTexture2D> MenuButtonObj(TEXT("/Game/UI/MainMenu/MenuButton"));
//	static ConstructorHelpers::FObjectFinder<UTexture2D> ResourceObj(TEXT("/Game/UI/HUD/Coin"));
//	static ConstructorHelpers::FObjectFinder<UTexture2D> LivesObj(TEXT("/Game/UI/HUD/Actions/Barrel"));


//	static ConstructorHelpers::FObjectFinder<UMaterial> HUDMousePointerNeutralObj(TEXT("/Game/UI/Pointers/Neutral"));
//	static ConstructorHelpers::FObjectFinder<UMaterial> HUDMousePointerAttackObj(TEXT("/Game/UI/Pointers/Enemy"));

	EnemyTeamHPTexture = EnemyTeamHealthBar.Object;
	BarFillTexture = BarFillObj.Object;
}

APlayerController* AMainHUD::GetPlayerController() const
{
	return Cast<APlayerController>(PlayerOwner);
}

void AMainHUD::DrawHUD()
{

	if (GEngine && GEngine->GameViewport)
	{
		FVector2D ViewportSize;
		GEngine->GameViewport->GetViewportSize(ViewportSize);
		UIScale = ViewportSize.X / 2048.0f;
	}

	Super::DrawHUD();
	bool bConsoleOpen = false;


	DrawActorsHealth();
}

void AMainHUD::DrawHealthBar(AActor* ForActor, float HealthPercentage, int32 BarHeight, int32 OffsetY = 0) const
{
	//
	FBox BB = ForActor->GetComponentsBoundingBox();
	FVector Center = BB.GetCenter();
	FVector Extent = BB.GetExtent();
	FVector2D Center2D = FVector2D(Canvas->Project(FVector(Center.X, Center.Y, Center.Z + Extent.Z)));
	float ActorExtent=40;
	//ActorExtent = Extent.Y*0.95f;

	//if (Cast<APawn>(ForActor) != NULL)
	//{
	//	AMainPawn* StrategyChar = Cast<AMainPawn>(ForActor);
	//	if ((StrategyChar != NULL) && (StrategyChar->GetCapsuleComponent() != NULL))
	//	{
	//		ActorExtent = StrategyChar->GetCapsuleComponent()->GetScaledCapsuleRadius();
	//	}
	//}
	//else if (Cast<AStrategyBuilding>(ForActor) != NULL)
	//{
	//	Center2D = FVector2D(Canvas->Project(ForActor->GetActorLocation()));
	//	ActorExtent = 60;
	//}

	FVector Pos1 = Canvas->Project(FVector(Center.X, Center.Y - ActorExtent * 2, Center.Z + Extent.Z));
	FVector Pos2 = Canvas->Project(FVector(Center.X, Center.Y + ActorExtent * 2, Center.Z + Extent.Z));
	float HealthBarLength = (Pos2 - Pos1).Size2D();

	APlayerController* MyPC = GetPlayerController();
	UTexture2D* HealthBarTexture = EnemyTeamHPTexture;

	float X = Center2D.X - HealthBarLength / 2;
	float Y = 0;
	if (OffsetY==0)
		Y = Center2D.Y - Extent.Y;
	else
		Y = Center2D.Y + OffsetY;
	FCanvasTileItem TileItem(FVector2D(X, Y), HealthBarTexture->Resource, FVector2D(HealthBarLength * HealthPercentage, BarHeight), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	TileItem.UV1 = FVector2D(HealthPercentage, 1.0f);

	Canvas->DrawItem(TileItem);
	//Fill the rest of health with gray gradient texture
	X = Center2D.X - HealthBarLength / 2 + HealthBarLength * HealthPercentage;
	
	if (OffsetY == 0)
		Y = Center2D.Y - Extent.Y;
	else
		Y = Center2D.Y + OffsetY;

	TileItem.Position = FVector2D(X, Y);
	TileItem.Texture = BarFillTexture->Resource;
	TileItem.UV1 = FVector2D(1.0f, 1.0f);
	TileItem.Size = FVector2D(HealthBarLength * (1.0f - HealthPercentage), BarHeight);
	TileItem.SetColor(FLinearColor(0.5f, 0.5f, 0.5f, 0.5f));
	Canvas->DrawItem(TileItem);
	//
}

void AMainHUD::DrawActorsHealth()
{
	for (FConstPawnIterator Iterator = GetWorld()->GetPawnIterator(); Iterator; ++Iterator)
	{
		AMainPawn* TestChar = Cast<AMainPawn>(*Iterator);
		if (TestChar != NULL && TestChar->GetHealth() > 0)
		{
			if (TestChar->IsHealthEnabled())//(AIController != NULL && TestChar->IsHealthEnabled())
			{
				DrawHealthBar(Cast<AActor>(TestChar), TestChar->GetHealth() / (float)TestChar->GetMaxHealth(), 18 * UIScale);
			}
		}
	}

}
