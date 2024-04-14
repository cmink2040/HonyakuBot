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

 	const FName name = "Roboto";
 	//const FString dir = "../../../Engine/Content/SlateDebug/Fonts/Roboto-Black.ttf";
 	const FString dir = TEXT("C:/Users/cmink/Documents/Unreal Projects/HonyakuBot/Content/Fonts/Roboto-Black.ttf");

 	TSharedPtr<const FCompositeFont> CompositeFont = MakeShared<FCompositeFont>(name, dir,  EFontHinting::Default, EFontLoadingPolicy::LazyLoad);

 	// Populate the FCompositeFont object with the necessary font data
 	// Example: Assume you have a font family named "Roboto", you would add it to the composite font

 	const FSlateBrush* greenb = FCoreStyle::Get().GetBrush("GreenBrush");
 	//const FSlateBrush* grayb = FCoreStyle::Get().GetBrush("LightGrayBrush");

 	
 	const TSharedPtr<const FSlateBrush> green = MakeShared<FSlateColorBrush>( FLinearColor(0.5f, 1.0f, 0.5f, 1.0f));
 	const TSharedPtr<const FSlateBrush> gray =  MakeShared<FSlateColorBrush>( FLinearColor(0.5f, 0.5f, 0.5f, 1.0f) );

 	
 	const FSlateBrush* greenptr = new FSlateColorBrush( FLinearColor(0.2f, 0.8f, 0.2f, 1.0f));
 	const FSlateBrush* grayptr =  new FSlateColorBrush( FLinearColor(0.3f, 0.3f, 0.3f, 1.0f));

 	if (!greenptr)
 	{
 		UE_LOG(LogTemp, Warning, TEXT("Green isn't valid"));
 		// Handle the case where the pointer is not valid
 		// For example, log an error message or take appropriate action
 	}

 	if (!grayptr)
 	{
 		UE_LOG(LogTemp, Warning, TEXT("Gray isn't valid"));

 	}
 	
 	//green->ImageSize = FVector2D(10.0f, 10.0f); // Set the image size
 	//green->TintColor = FLinearColor(0.5f, 1.0f, 0.5f, 1.0f); // Set the tint color

 	//gray->ImageSize = FVector2D(15.0f, 10.0f); // Set the image size
 	//gray->TintColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f); // Set the tint color

 	//const FSlateBrush *bar3 = FCoreStyle::Get().GetBrush("GreenBrush");

 	//UE_LOG(LogTemp, Warning, TEXT("HMMMMMMMMMMM %f"), ReadHealth());

 	// Create a text block with "Hello, Slate!" text
 	// Create a box to center the text block and give it black background
	ChildSlot
  [
  SNew(SBox)
   .HAlign(HAlign_Center) // Center horizontally
   .VAlign(VAlign_Bottom) // Center vertically
  	[SNew(SOverlay)
  	+SOverlay::Slot()
  	[ SNew(SOverlay)
		  // Background rectangle
		  

		  // Health fill rectangle
		  + SOverlay::Slot()
		  .HAlign(HAlign_Left)
		  [
		  	SNew(SImage)
				 .Image( grayptr) // Use a black brush for a solid color background
		  	.DesiredSizeOverride(FVector2d(280, 1))


			 
		  ]
  		+ SOverlay::Slot()
		  .HAlign(HAlign_Left)
		  [
			  SNew(SImage)
				  .Image( greenptr ) // Use a white brush for a solid color background
		  			.DesiredSizeOverride(FVector2d(200, 1))
			
			  
		  ]
			]
  		+SOverlay::Slot()
  [SNew(STextBlock)
  		
	  .Text_Lambda([this]() { return FText::FromString(FString::Printf(TEXT("Health: %f"), ReadHealth())); })
	  .Font(FSlateFontInfo(CompositeFont, 15)) // Specify font family and size
	   .ColorAndOpacity(FLinearColor(0.9f, 0.9f, 0.9f, 1.0f)) // Set color to red
]
		]
	  
  ];
 
 	
 }
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

