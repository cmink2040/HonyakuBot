// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MC.generated.h"

UCLASS()
class HONYAKUBOT_API AMC : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMC();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void MoveForward(float Value);
	void MoveRight(float Value);

	
	void MoveLeft(float Value);
	void MoveBackward(float Value);

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;
private:

	FVector CurrentVelocity;
	float MoveSpeed = 1000.0f; // Adjust this to control movement speed

};
