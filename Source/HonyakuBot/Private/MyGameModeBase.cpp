// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MC.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"




void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Find existing pawn instances in the level
    TArray<AActor*> AllActors;
    
    TArray<AMC*> ExistingPawns;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), AllActors);
  
    // Check if there's at least one existing pawn of the specified class
    if (ExistingPawns.Num() > 0)
    {
        // Get the first existing pawn found
        AMC* ExistingPawn = ExistingPawns[0];
    
        // Now you have a reference to the existing pawn and you can use it as needed
        
        // Spawn and possess the pawn
        AMC* NewPawn = GetWorld()->SpawnActor<AMC>(AMC::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
        PlayerController->Possess(ExistingPawn);
    }
}

