// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InterfaceHUD.h"

#include "Styling/SlateTypes.h"

#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
 float AInterfaceHUD::ReadHealth()
{
	if(PlayerCharacter != nullptr)
	{
		PlayerCharacter->SetHealth(PlayerCharacter->GetHealth()-1);
		return PlayerCharacter->GetHealth();
	}
	else
	{
		return 0.00f;
	}
}
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void AInterfaceHUD::Construct(const FArguments& InArgs)
 {
 	// Create a black background
 	bCanSupportFocus = true;
 	PlayerCharacter = InArgs._PlayerCharacter;


 	UE_LOG(LogTemp, Warning, TEXT("HMMMMMMMMMMM %f"), ReadHealth());

 	// Create a text block with "Hello, Slate!" text
 	// Create a box to center the text block and give it black background
	ChildSlot
  [
  SNew(SBox)
  .HAlign(HAlign_Center) // Center horizontally
   .VAlign(VAlign_Center) // Center vertically
	
	  [SNew(STextBlock)
	   .Text_Lambda([this]() { return FText::FromString(FString::Printf(TEXT("Clicks: %f"), ReadHealth())); })
	]  
  ];
 
 	
 }
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

