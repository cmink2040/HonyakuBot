// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MC.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Spawn and possess the pawn
    AMC* NewPawn = GetWorld()->SpawnActor<AMC>(AMC::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    PlayerController->Possess(NewPawn);
}