// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "MenuWidget.h"

bool UMenuWidget::Setup()
{
	this->AddToViewport();

	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	if (!ensure(Controller != nullptr)) return false;

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(this->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	Controller->SetInputMode(InputMode);
	Controller->bShowMouseCursor = true;
	return true;
}

void UMenuWidget::TearDown()
{
	FInputModeGameOnly InputModeData;
	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	Controller->SetInputMode(InputModeData);
	Controller->bShowMouseCursor = false;
}


void UMenuWidget::OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);

	this->TearDown();
}

void UMenuWidget::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}