// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
	//UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformsGameInstance Constructor"));
}

void UPuzzlePlatformsGameInstance::Init()
{
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString &Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;


	APlayerController* Controller = GetFirstLocalPlayerController();
	if (!ensure(Controller != nullptr)) return;

	Controller->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	
}
