// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Main.h"
#include "GameFramework/PlayerController.h"

#include "UI/InterfaceHUD.h"
#include "Kismet/GameplayStatics.h"
void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Find existing pawn instances in the level
    TArray<AActor*> AllActors;
    
    TArray<AMain*> ExistingPawns;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMain::StaticClass(), AllActors);
	UE_LOG(LogTemp, Warning, TEXT("HTEST TEST 1"));

	UE_LOG(LogTemp, Warning, TEXT("ExistingPawn %d"),GetWorld()->GetActorCount());

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		AMain* PlayerCharacter = Cast<AMain>(PC->GetPawn());
		if (PlayerCharacter)
		{
			ExistingPawn = PlayerCharacter;
			UE_LOG(LogTemp, Warning, TEXT("HM %f"), ExistingPawn->GetHealth());
			UE_LOG(LogTemp, Warning, TEXT("HTEST TEST 2"));
			MySlateUI = SNew(AInterfaceHUD).PlayerCharacter(MakeWeakObjectPtr(ExistingPawn));

			GEngine->GameViewport->AddViewportWidgetContent(MySlateUI.ToSharedRef());
			PC->Possess(ExistingPawn);


		}
	}
   
}

