// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Camera/CameraComponent.h"


#include "STerminal.h"


#include "Main.generated.h"

UCLASS()
class HONYAKUBOT_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMain();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	void InputMove(const FInputActionValue& Value);

	void CamLook(const FInputActionValue& Value);

	void Interact(const FInputActionValue& Value);

	bool GUIOpen = false;

	TSharedPtr<STerminal> MySlateWidget;

	
	UPROPERTY(EditAnywhere, Category="Set Up")
	USceneComponent* VisibleMesh;
	
	UPROPERTY(EditAnywhere, Category="Set Up");
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputAction* inputMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputAction* Look;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputAction* OpenUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputMappingContext* inputMappingContext;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:

};
