// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "My2DShooterGameInstance.h"

UMy2DShooterGameInstance::UMy2DShooterGameInstance()
{
	this->Score = 0;
}

int UMy2DShooterGameInstance::ChangeScore(int Delta)
{
	this->Score += Delta;
	if (this->Score<0)
		this->Score = 0;
	return this->Score;
}

int UMy2DShooterGameInstance::GetScore()
{
	return this->Score;
}

void UMy2DShooterGameInstance::SetScore(int NewScore)
{
	this->Score = NewScore;
}
