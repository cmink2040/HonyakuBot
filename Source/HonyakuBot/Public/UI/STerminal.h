// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class HONYAKUBOT_API STerminal : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STerminal)
	{}
	SLATE_END_ARGS()

	FString results;
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override {return true;};

private:

	// Text box for entering a name
	TSharedPtr<SEditableTextBox> NameTextBox;

	// Text box for entering an email
	TSharedPtr<SEditableTextBox> EmailTextBox;

	FReply OnSubmitClicked();


};
