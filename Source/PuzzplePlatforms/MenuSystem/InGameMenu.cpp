// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"




bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;


	bool SetupResult = Setup();

	return SetupResult;
}