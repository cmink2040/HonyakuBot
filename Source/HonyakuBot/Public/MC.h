// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "MC.generated.h"

UCLASS()
class HONYAKUBOT_API AMC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMC();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	
	void InputMove(const FInputActionValue& Value);
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputAction* inputMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputMappingContext* inputMappingContext;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;
private:

	FVector CurrentVelocityX;
	FVector CurrentVelocityY;

	float MoveSpeed = 1000.0f; // Adjust this to control movement speed

};
