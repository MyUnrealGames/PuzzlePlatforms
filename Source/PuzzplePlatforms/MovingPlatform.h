// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZPLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category="Setup")
	float Speed = 20.f;

	UPROPERTY(EditAnywhere, Category = "Setup", Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	FVector GlobalTargetLocation;

	FVector GlobalStartLocation;

};
