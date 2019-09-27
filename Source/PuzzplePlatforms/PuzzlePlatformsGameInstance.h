// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

private:
	TSubclassOf<class UUserWidget> MenuClass;

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);
	
	void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	virtual void HostButton() override;

	UFUNCTION(Exec)
	void JoinButton(const FString &Address);
};
