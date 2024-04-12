// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <cstdio>   // For popen(), pclose()
#include <cstring>  // For strerror()

#include <vector>

#include "CoreMinimal.h"

class HONYAKUBOT_API Aictl
{
public:

	FString  aictl(const char* venvdir, const char* pypath, const char* pydir, TArray<const char*> args);

};
