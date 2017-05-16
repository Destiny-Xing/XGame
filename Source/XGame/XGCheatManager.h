// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CheatManager.h"
#include "XGCheatManager.generated.h"

/**
 * 
 */
UCLASS(within = XGamePlayerController)
class XGAME_API UXGCheatManager : public UCheatManager
{
	GENERATED_BODY()
	
public:
	UFUNCTION(exec)
	void StartGame();
	
};
