// Fill out your copyright notice in the Description page of Project Settings.

#include "StaticLogic.h"


FVector UStaticLogic::GetRandomPos(FVector Min, FVector Max)
{
	float X = FMath::RandRange(Min.X, Max.X);
	float Y = FMath::RandRange(Min.Y, Max.Y);
	float Z = FMath::RandRange(Min.Z, Max.Z);
	//	
	return FVector(X, Y, Z);
}

FVector UStaticLogic::GetRandomPos(FMyGameZone Zone)
{
	return FVector();
}
