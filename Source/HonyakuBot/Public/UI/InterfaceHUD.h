// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/InterfaceHUD.h"
#include "Main.h"
/**
 * 
 */
class HONYAKUBOT_API AInterfaceHUD : public SCompoundWidget
{

	
public:
	SLATE_BEGIN_ARGS(AInterfaceHUD)
	: _PlayerCharacter(nullptr)

	{}
	SLATE_ARGUMENT(TWeakObjectPtr<AMain>, PlayerCharacter)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override {return true;};

	 float ReadHealth();

	// Text box for entering a name
private:
	TWeakObjectPtr<AMain> PlayerCharacter;


};