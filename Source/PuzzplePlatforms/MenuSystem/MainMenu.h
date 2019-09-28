// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"


/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld) override;

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

	
private:
	// MainMenu Properties and Functions

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();


	// JoinMenu Properties and Functions

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressField;

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void OpenMainMenu();

	// Interface

	IMenuInterface* MenuInterface;
};
