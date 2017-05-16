// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "XGame.h"
#include "XGamePlayerController.h"
#include "XGCheatManager.h"

AXGamePlayerController::AXGamePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	CheatClass = UXGCheatManager::StaticClass();
}
