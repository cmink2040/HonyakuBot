// Fill out your copyright notice in the Description page of Project Settings.


#include "STerminal.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"

#include "Aictl.h"
#include "Styling/SlateTypes.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STerminal::Construct(const FArguments& InArgs)
{
	// Create a black background
	bCanSupportFocus = true;

	UE_LOG(LogTemp, Warning, TEXT("HMMMMMMMMMMM %s"), *results);

	// Create a text block with "Hello, Slate!" text
	// Create a box to center the text block and give it black background
	ChildSlot
	[
	SNew(SBox)
	   .HAlign(HAlign_Center) // Center horizontally
	   .VAlign(VAlign_Fill) // Center vertically
	   
	[
	  SNew(SVerticalBox)
	  + SVerticalBox::Slot()
	  .Padding(10)
	  [
		  SAssignNew(NameTextBox, SEditableTextBox)
		  .HintText(FText::FromString(results))
	  ]
	  + SVerticalBox::Slot()
	  .Padding(10)
	  [
		  SAssignNew(EmailTextBox, SEditableTextBox)
		  .HintText(FText::FromString(TEXT("Prompt")))
	  ]
	  + SVerticalBox::Slot()
	  .Padding(10)
	  [
		  SNew(SButton)
		  .Text(FText::FromString(TEXT("Submit")))
		  .OnClicked(this, &STerminal::OnSubmitClicked)
	  ]

	]
  ];
}

FReply STerminal::OnSubmitClicked()
{
	// Get the entered name and email
	FString Name = NameTextBox->GetText().ToString();
	FString Email = EmailTextBox->GetText().ToString();
	
	Aictl* a = new Aictl();

	const char *vendir = "f";
	const char *pypath = "f";
	const char *pydir = "f";
	TArray<const char*> Template;
	Template.Add("ff");

	
	results = a->aictl(vendir, pypath, pydir, Template);
	UE_LOG(LogTemp, Warning, TEXT("HMMMMMMMMMMM RESULTS %s"), *results);

	UE_LOG(LogTemp, Warning, TEXT("CLICKED"));
	// TODO: Handle the submitted data (e.g., validate and process it)

	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
