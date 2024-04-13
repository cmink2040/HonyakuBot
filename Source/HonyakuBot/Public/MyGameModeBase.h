// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Main.h"
#include "UI/InterfaceHUD.h"
#include "MyGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class HONYAKUBOT_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;

private:
	 TSharedPtr<AInterfaceHUD> MySlateUI;
	 AMain* ExistingPawn; 
};