// Fill out your copyright notice in the Description page of Project Settings.

//#include "My2DShooter.h"
#include "MainLevelWidget.h"

void UMainLevelWidget::SetMaxFuel(int MaxFuel)
{
	this->MaxLevelFuel = MaxFuel;
}

int UMainLevelWidget::GetMaxFuel()
{
	return this->MaxLevelFuel;
}

void UMainLevelWidget::SetCurrentFuel(int CurrentFuelNum)
{
	this->CurrLevelFuel = CurrentFuelNum;
}

